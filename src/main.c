/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 15:53:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	init(t_env *e)
{
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	getmaxyx(stdscr, e->row, e->col);
	if (!valid_size(e)) // check if screen is big enough
		return (false);
	if (!menu()) // choosing size of board
		return (false);
	return (true);
}

int	main(void)
{
	t_env	e;

	if (!init(&e))
		return (1);
	key = 0;
	while (!is_exit(key))
	{
		// clear
		//
	}
	endwin();
	return (0);
}
