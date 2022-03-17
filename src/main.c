/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 20:28:07 by adelille         ###   ########.fr       */
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
	srand(time(NULL));
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
	while (true /*!lose()*/)
	{
		// clear maybe
		e.key = 0;
		while (!is_arrow(e.key))
		{
			e.key = getch();
			if (is_exit(e.key))
				break ;
		}
		// handle arrow
		insert(&e);
		// print_map(e); // with score and print win if win
	}
	// bonus: ask for pseudo and save score
	return (end(&e, 0));
}
