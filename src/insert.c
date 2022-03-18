/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:43:41 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 23:36:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	empty_access(size_t **map, const size_t size,
		const size_t val, const size_t index)
{
	size_t	i;
	size_t	row;
	size_t	col;

	i = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (map[row][col] == 0)
			{
				if (i == index)
				{
					map[row][col] = val;
					return (true);
				}
				i++;
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

	//if (rand() % 4 == 0) // 1/4 that val=4 and 3/4 that val=2
	if (rand() % CHANCE_4 == 0)
		val = 4;
	else
		val = 2;
	return (empty_access(e->map, e->size, val,
			rand() % empty_count(e->map, e->size)));
	// WARNING: if empty_count is 0: floating exception
	// I won't put a protection yet
	// the code should not go into insert if empty_count == 0
	// So will make sure it doesn't happend
}
