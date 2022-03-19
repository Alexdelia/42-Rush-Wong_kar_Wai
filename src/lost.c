/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:46:48 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 15:22:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

bool	can_fuse_row(size_t **map, const size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size - 1)
		{
			if (map[y][x] == map[y + 1][x])
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

bool	can_fuse_col(size_t **map, const size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size - 1)
		{
			if (map[x][y] == map[x][y + 1])
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

bool	lost(t_env *e)
{
	if (!empty_count(e->map, e->size)
		&& !can_fuse_row(e->map, e->size)
		&& !can_fuse_col(e->map, e->size))
	{
		e->state = STATE_LOST;
		return (true);
	}
	return (false);
}
