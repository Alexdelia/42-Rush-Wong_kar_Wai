/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:53:55 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 18:36:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

bool	resize(t_env *e)
{
	getmaxyx(stdscr, e->row, e->col);
	attrset(A_BOLD | COLOR_PAIR(CP_RED));
	while (!valid_size(e))
	{
		clear();
		mvprintw(0, 0, "⌜");
		mvprintw(0, e->col - 1, "⌝");
		mvprintw(e->row - 1, 0, "⌞");
		mvprintw(e->row - 1, e->col - 1, "⌟");
		pmw(e, "too small");
		refresh();
		e->key = 0;
		while (e->key != KEY_RESIZE)
		{
			e->key = getch();
			if (is_exit(e->key))
				return (false);
		}
		getmaxyx(stdscr, e->row, e->col);
	}
	attrset(A_NORMAL);
	// might need to show the board again
	return (true);
}
