/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:32:17 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 19:35:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

void	print_frame(t_env *e, const int color)
{
	size_t	i;

	attrset(COLOR_PAIR(color));
	addstr("╔");
	i = 0;
	while (++i < (size_t)e->col - 1)
		addstr("═");
	addstr("╗");
	i = 0;
	while (++i < (size_t)e->row - 1)
	{
		mvaddstr(i, 0, "║");
		mvaddstr(i, e->col - 1, "║");
	}
	move(i, 0);
	addstr("╚");
	i = 0;
	while (++i < (size_t)e->col - 1)
		addstr("═");
	addstr("╝");
	attrset(A_NORMAL);
}

void	print_menu(t_env *e)
{
	print_frame(e, CP_MENU);
	attrset(A_BOLD | COLOR_PAIR(CP_PLAY));
	mvprintw((e->row - 1) / 2 - 1,
		(e->col - ft_strlen(MSG_PLAY)) / 2, MSG_PLAY);
	attrset(A_BOLD | COLOR_PAIR(get_color(2048)));
	mvprintw((e->row - 1) / 2,
		(e->col - ft_strlen(MSG_SCORE)) / 2 - 1, MSG_SCORE);
	attrset(A_BOLD | COLOR_PAIR(get_color(64)));
	mvprintw((e->row - 1) / 2 + 1,
		(e->col - ft_strlen(MSG_EXIT)) / 2, MSG_EXIT);
	move((e->row - 1) / 2 + 2, (e->col - ft_strlen("[p/s/q]")) / 2 - 1);
	attrset(A_NORMAL);
	addch('[');
	attrset(COLOR_PAIR(CP_PLAY));
	addch('p');
	attrset(A_NORMAL);
	addch('/');
	attrset(COLOR_PAIR(get_color(2048)));
	addch('s');
	attrset(A_NORMAL);
	addch('/');
	attrset(COLOR_PAIR(get_color(64)));
	addch('q');
	attrset(A_NORMAL);
	addch(']');
}
