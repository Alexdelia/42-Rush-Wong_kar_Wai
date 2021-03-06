/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuse.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:03:22 by adelille          #+#    #+#             */
/*   Updated: 2022/03/20 11:37:49 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

bool	fuse_up(t_env *e)
{
	size_t	row;
	size_t	col;
	bool	ret;

	ret = false;
	col = -1;
	while (++col < e->size)
	{
		row = -1;
		while (++row < e->size - 1)
		{
			if (e->map[row][col]
					&& e->map[row][col] == e->map[row + 1][col])
			{
				e->map[row][col] += e->map[row + 1][col];
				e->map[row + 1][col] = 0;
				ret = true;
				e->score += e->map[row][col];
				if (e->map[row][col] > e->top)
					e->top = e->map[row][col];
			}
		}
	}
	return (ret);
}

bool	fuse_down(t_env *e)
{
	size_t	row;
	size_t	col;
	bool	ret;

	ret = false;
	col = -1;
	while (++col < e->size)
	{
		row = e->size;
		while (--row > 0)
		{
			if (e->map[row][col]
					&& e->map[row][col] == e->map[row - 1][col])
			{
				e->map[row][col] += e->map[row - 1][col];
				e->map[row - 1][col] = 0;
				ret = true;
				e->score += e->map[row][col];
				if (e->map[row][col] > e->top)
					e->top = e->map[row][col];
			}
		}
	}
	return (ret);
}

bool	fuse_left(t_env *e)
{
	size_t	row;
	size_t	col;
	bool	ret;

	ret = false;
	row = -1;
	while (++row < e->size)
	{
		col = -1;
		while (++col < e->size - 1)
		{
			if (e->map[row][col]
					&& e->map[row][col] == e->map[row][col + 1])
			{
				e->map[row][col] += e->map[row][col + 1];
				e->map[row][col + 1] = 0;
				ret = true;
				e->score += e->map[row][col];
				if (e->map[row][col] > e->top)
					e->top = e->map[row][col];
			}
		}
	}
	return (ret);
}

bool	fuse_right(t_env *e)
{
	size_t	row;
	size_t	col;
	bool	ret;

	ret = false;
	row = -1;
	while (++row < e->size)
	{
		col = e->size;
		while (--col > 0)
		{
			if (e->map[row][col]
					&& e->map[row][col] == e->map[row][col - 1])
			{
				e->map[row][col] += e->map[row][col - 1];
				e->map[row][col - 1] = 0;
				ret = true;
				e->score += e->map[row][col];
				if (e->map[row][col] > e->top)
					e->top = e->map[row][col];
			}
		}
	}
	return (ret);
}
