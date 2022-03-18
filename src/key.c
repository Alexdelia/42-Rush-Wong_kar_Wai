/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:53:55 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 14:35:53 by adelille         ###   ########.fr       */
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

bool	key_handle(t_env *e)
{
	bool	ret;

	ret = false;
	if (e->key == KEY_UP || e->key == KEY_W)
		ret = move_up(e) | fuse_up(e) | move_up(e);
		//ret |= fuse_up(e);
		//ret |= move_up(e);
	else if (e->key == KEY_DOWN || e->key == KEY_S)
		return (move_down(e));
	else if (e->key == KEY_LEFT || e->key == KEY_A)
		return (move_left(e));
	else if (e->key == KEY_RIGHT || e->key == KEY_D)
		return (move_right(e));
	return (ret); // return true if move occured
}
