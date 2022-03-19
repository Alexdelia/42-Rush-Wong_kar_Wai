/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:53:55 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 15:23:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static void	resize_frame(t_env *e)
{
	mvprintw(0, 0, "⌜");
	mvprintw(0, e->col - 1, "⌝");
	mvprintw(e->row - 1, 0, "⌞");
	mvprintw(e->row - 1, e->col - 1, "⌟");
}

bool	resize(t_env *e)
{
	getmaxyx(stdscr, e->row, e->col);
	attrset(A_BOLD | COLOR_PAIR(CP_RED));
	while (!valid_size(e))
	{
		clear();
		if (!NO_UNICODE)
			resize_frame(e);
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
	return (true);
}

bool	key_handle(t_env *e)
{
	bool	ret;

	ret = false;
	if (e->key == KEY_UP || e->key == 'w')
		ret = move_up(e) | fuse_up(e) | move_up(e);
	else if (e->key == KEY_DOWN || e->key == 's')
		ret = move_down(e) | fuse_down(e) | move_down(e);
	else if (e->key == KEY_LEFT || e->key == 'a')
		ret = move_left(e) | fuse_left(e) | move_left(e);
	else if (e->key == KEY_RIGHT || e->key == 'd')
		ret = move_right(e) | fuse_right(e) | move_right(e);
	return (ret);
}
