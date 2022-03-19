/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:11:41 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 13:26:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

static void	print_win(t_env *e)
{
	size_t	i;

	addch('\n');
	i = -1;
	while (++i < (e->col - ft_strlen(MSG_WON)) / 2)
		addch(' ');
	addstr(MSG_WON);
	e->state = STATE_WON;
}

static void	print_map_score(t_env *e)
{
	mvprintw(1, (e->col - (ft_strlen(MSG_CUR_SCORE) + 1
				+ ft_stlen(e->score))) / 2,
		"%s %ld\n", MSG_CUR_SCORE, e->score);
}

static void	print_board(const int row, const int col, const size_t size)
{
	size_t	x;
	size_t	y;

	attrset(COLOR_PAIR(CP_BOARD));
	y = -1;
	while (++y < size + 1)
	{
		move(row + (y * 6), col);
		x = -1;
		while (++x < size * 12 + 2)
			addch(' ');
	}
	y = -1;
	while (++y < size + 1)
	{
		x = -1;
		while (++x < size * 6)
			mvaddstr(row + x, col + (y * 12), "  ");
	}
	attrset(A_NORMAL);
}

static void	print_tile(const size_t val, const size_t row, const size_t col)
{
	attrset(COLOR_PAIR(get_color((int)val)));

	// debug
	//attrset(COLOR_PAIR(CP_RED));
	//printw("%d", get_color((int)val));

	if (NO_UNICODE || val == 0 || val > 4096)
	{
		mvaddstr(row, col, "          ");
		mvaddstr(row + 1, col, "          ");
		mvaddstr(row + 2, col, "          ");
		mvaddstr(row + 3, col, "          ");
		mvaddstr(row + 4, col, "          ");
		if (val > 0 && val < 128)
			mvprintw(row + 2, (9 + ft_stlen(val)) / 2 + col - 1, "%ld", val);
		else if (val)
			mvprintw(row + 2, (9 + ft_stlen(val)) / 2 + col - 2, "%ld", val);
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

	// need to calc starting row and col
	// need to find how much to move row and col each tile
	find_starting_row_col(e, &starting_row, &starting_col);
	print_map_score(e);
	print_board(starting_row, starting_col, e->size);
	//print_board(0, 0, e->size);
	row = 0;
	while (row < e->size)
	{
		col = 0;
		while (col < e->size)
		{
			//printw("|%ld", e->map[row][col]);
			//printw("|");
			print_tile(e->map[row][col],
				row * 6 + 1 + starting_row, col * 12 + 2 + starting_col);
			col++;
		}
		//printw("|\n");
		row++;
	}
	//print_wall(e->size * 2 - 1);
	if (e->state == STATE_NO && e->top == WIN_VALUE)
		print_win(e);
	//refresh();
}
