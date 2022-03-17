/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 17:07:09 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	menu(t_env *e)
{
	e->key = 0;
	while (e->size < MIN_BOARD || e->size > MAX_BOARD)
	{
		clear();
		if (e->key != 0)
			printw("Error: size of board should be between, %d and %d",
					MIN_BOARD, MAX_BOARD);
		pmw(e, "please enter size of board");
		e->key = getch();
		if (is_exit(e->key))
			return (false);
		e->size = (char)e->key - '0';
	}
	clear();
	return (true);
}

static bool	init(t_env *e)
{
	e->map = NULL;
	e->size = 0;
	e->score = 0;
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	if (!resize(e))
		return (false);
	if (!menu(e)) // choosing size of board
		return (false);
	return (true);
}

int	main(void)
{
	t_env	e;

	if (!init(&e))
		return (end(&e, 1));
	e.key = 0;
	while (!is_exit(e.key) /* || win */)
	{
		// clear maybe
		//
		e.key = getch();
	}
	// bonus: ask for pseudo and save score
	endwin();
	return (0);
}
