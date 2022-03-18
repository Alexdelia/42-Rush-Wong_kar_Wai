/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 23:39:33 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 23:54:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static void	print_frame_score_end(t_env *e, size_t i)
{
	mvaddstr(i, 4, "▏  ╱");
	mvaddstr(i + 1, 4, "╲ˍ╱S");
	move(i - 1, 8);
	i = 0;
	while (++i < (size_t)e->col - 10)
		addstr("_");
	move(e->row - 2, 8);
	i = 0;
	while (++i < (size_t)e->col - 10)
		addstr("_");
	mvaddstr(e->row - 4, e->col - 2, "_");
	mvaddstr(e->row - 3, e->col - 2, "╱.");
	mvaddstr(e->row - 2, e->col - 3, "╱.");
}

void	print_frame_score(t_env *e, const int color)
{
	size_t	i;

	attrset(A_BOLD | COLOR_PAIR(color));
	move(0, 2);
	i = 0;
	while (++i < (size_t)e->col - 5)
		addstr("_");
	mvaddstr(1, 1, "╱ ╲");
	mvaddstr(2, 1, "▏  ▏");
	mvaddstr(3, 1, "╲ˍˍ▏");
	mvaddstr(1, e->col - 4, "╲.");
	i = 1;
	while (++i < (size_t)e->row - 3)
	{
		mvaddstr(i, 4, "▏");
		mvaddstr(i, e->col - 3, "▏.");
	}
	print_frame_score_end(e, i);
	attrset(A_NORMAL);
}

void	print_score(t_env *e, t_score *s, const size_t *sort)
{
	size_t	i;

	i = 0;
	attrset(A_BOLD);
	while (i < (size_t)e->row - 7 && i < MAX_READ_SCORE && s[sort[i]].score > 0)
	{
		if (i == 0)
			mvaddstr(3, 6, "🏆");
		mvaddstr(3 + i, 8, s[sort[i]].pseudo);
		mvprintw(3 + i, (e->col - ft_stlen(s[sort[i]].score)) / 2 + 3,
			"%ld", s[sort[i]].score);
		attron(COLOR_PAIR(get_color(s[sort[i]].top)));
		mvprintw(3 + i, e->col - 9, "%ld", s[sort[i]].top);
		attroff(COLOR_PAIR(get_color(s[sort[i]].top)));
		i++;
	}
	attrset(A_NORMAL);
}
