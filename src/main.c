/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 19:21:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	init_colors(void)
{
	if (!has_colors())
		return (!ft_ps("Error: your terminal doesn't support colors\n"));
	start_color();
	init_pair(CP_RED, COLOR_RED, COLOR_BLACK);
	return (true);
}

static bool	init(t_env *e)
{
	e->map = NULL;
	e->size = 0;
	e->score = 0;
	setlocale(LC_ALL, "");
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	if (!init_colors())
		return (false);
	if (!resize(e))
		return (false);
	return (true);
}

int	main(void)
{
	t_env	e;

	if (!init(&e))
		return (end(&e, 1));
	if (!menu(&e)) // choosing size of board
		return (end(&e, 2));
	e.key = 0;
	while (!is_exit(e.key) /* || win */)
	{
		// clear maybe
		//
		e.key = getch();
	}
	// bonus: ask for pseudo and save score
	return (end(&e, 0));
}
