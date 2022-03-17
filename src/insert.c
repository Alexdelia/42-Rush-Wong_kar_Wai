/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:43:41 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 20:48:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

// here the index start at 1 and not 0
static bool	empty_access(t_env *e, const size_t index,
		size_t *row_output, size_t *col_output)
{
	size_t	i;
	size_t	row;
	size_t	col;

	i = 0;
	row = 0;
	while (row < e->size)
	{
		col = 0;
		while (col < e->size)
		{
			if (e->map[row][col] == 0)
			{
				i++;
				if (i == index)
				{
					*row_output = row;
					*col_output = col;
					return (true);
				}
			}
			col++;
		}
		row++;
	}
	return (false);
}

size_t	empty_count(size_t **map, const size_t size)
{
	size_t	count;
	size_t	row;
	size_t	col;

	count = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (map[row][col] == 0)
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

bool	insert(t_env *e)
{
	size_t	val;
	size_t	index;
	bool	ret;

	if (rand() % 4 == 0) // 1/4 that val=4 and 3/4 that val=2
		val = 4;
	else
		val = 2;
	index = rand() % empty_count(e->map, e->size);
	ret = empty_access(e, index, &e->row_last_insert, &e->col_last_insert);
	e->map[e->row_last_insert][e->col_last_insert] = val;
	return (ret);
}
