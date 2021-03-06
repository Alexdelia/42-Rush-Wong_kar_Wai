/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:11:41 by adelille          #+#    #+#             */
/*   Updated: 2022/03/20 14:37:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

static void	print_win(t_env *e)
{
	attrset(A_BOLD | COLOR_PAIR(CP_PLAY));
	mvaddstr(e->row - 2, (e->col - ft_strlen(MSG_WON)) / 2, MSG_WON);
	attrset(A_NORMAL);
	e->state = STATE_WON;
}

static void	print_map_score(t_env *e)
{
	attrset(A_BOLD | COLOR_PAIR(get_color(e->top)));
	mvprintw(1, (e->col - (ft_strlen(MSG_CUR_SCORE) + 3
				+ ft_stlen(e->score))) / 2,
		" %s %ld ", MSG_CUR_SCORE, e->score);
	attrset(A_NORMAL);
}

static void	print_board(const int row, const int col, const size_t size)
{
	size_t	x;
	size_t	y;

	attrset(COLOR_PAIR(CP_BOARD));
	y = -1;
	while (++y < size + 1)
	{
		move(row + (y * (TILE_ROW + 1)), col);
		x = -1;
		while (++x < size * (TILE_COL + 2))
			addch(' ');
	}
	y = -1;
	while (++y < size + 1)
	{
		x = -1;
		while (++x < size * (TILE_ROW + 1) + 1)
			mvaddstr(row + x, col + (y * (TILE_COL + 2)), "  ");
	}
	attrset(A_NORMAL);
}

static void	print_tile(const size_t val, const size_t row, const size_t col)
{
	attrset(COLOR_PAIR(get_color((int)val)));
	if (NO_UNICODE || val == 0 || val > 4096)
	{
		mvaddstr(row, col, "          ");
		mvaddstr(row + 1, col, "          ");
		mvaddstr(row + 2, col, "          ");
		mvaddstr(row + 3, col, "          ");
		mvaddstr(row + 4, col, "          ");
		if (val)
			mvprintw(row + 2, (TILE_COL - ft_stlen(val)) / 2 + col, "%ld", val);
	}
	else
		print_ascii(val, (int)row, (int)col);
	attrset(A_NORMAL);
}

void	print_map(t_env *e)
{
	size_t	row;
	size_t	col;
	size_t	starting_row;
	size_t	starting_col;

	find_starting_row_col(e, &starting_row, &starting_col);
	if (e->top == WIN_VALUE * 2)
		clear();
	print_map_score(e);
	print_board(starting_row - 1, starting_col, e->size);
	row = 0;
	while (row < e->size)
	{
		col = 0;
		while (col < e->size)
		{
			print_tile(e->map[row][col],
				row * (TILE_ROW + 1) + starting_row,
				col * (TILE_COL + 2) + 2 + starting_col);
			col++;
		}
		row++;
	}
	if (e->top == WIN_VALUE)
		print_win(e);
}
