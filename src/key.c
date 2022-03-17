/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:53:55 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 16:13:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

bool	resize(t_env *e)
{
	int		key;

	getmaxyx(stdscr, e->row, e->col);
	key = 0;
	while (!valid_size(e))
	{
		endwin();
		ft_ps("The window is too small\nplease resize it\n");
		key = 0;
		while (key != KEY_RESIZE)
		{
			key = getch();
			if (is_exit(key))
				return (false);
		}
		getmaxyx(stdscr, e->row, e->col);
	}
	if (key == KEY_RESIZE)
		initscr();
	// might need to show the board again
	return (true);
}
