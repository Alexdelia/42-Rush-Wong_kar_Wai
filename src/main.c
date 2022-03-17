/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 19:06:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	menu(t_env *e)
{
	e->key = 0;
	while (e->size < MIN_BOARD || e->size > MAX_BOARD)
	{
		clear();
		if (e->size != 0)
			printw("ERROR: size of board should be between, %d and %d",
					MIN_BOARD, MAX_BOARD); //
		pmw(e, "😃please enter size of board");
		e->key = getch();
		if (is_exit(e->key))
			return (false);
		else if (e->key == KEY_RESIZE)
		{
			e->size = 0;
			if (!resize(e))
				return (false);
		}
		else
			e->size = (char)e->key - '0';
	}
	clear();
	return (true);
}

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
