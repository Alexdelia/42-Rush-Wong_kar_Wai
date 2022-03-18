/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:11:41 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 14:18:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static void	print_score(t_env *e)
{
	mvprintw(1, (e->col - (ft_strlen("SCORE: ") + ft_stlen(e->score))) / 2,
		"SCORE: %ld\n", e->score);
}

static void	print_wall(const size_t size)
{
	size_t	i;

	i = -1;
	printw("x");
	while (++i < size)
		printw("-");
	printw("x\n");
}

static void	print_char_color(const size_t val)
{
	attrset(COLOR_PAIR(get_color((int)val)));

	// debug
	//attrset(COLOR_PAIR(CP_RED));
	//printw("%d", get_color((int)val));

	print_symbol(val);
	attrset(A_NORMAL);
}

void	print_map(t_env *e)
{
	size_t	row;
	size_t	col;

	print_score(e);
	print_wall(e->size * 2 - 1);
	row = 0;
	while (row < e->size)
	{
		col = 0;
		while (col < e->size)
		{
			//printw("|%ld", e->map[row][col]);
			printw("|");
			print_char_color(e->map[row][col]);
			col++;
		}
		printw("|\n");
		row++;
	}
	print_wall(e->size * 2 - 1);
}
