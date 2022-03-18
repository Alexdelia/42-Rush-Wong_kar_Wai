/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:03:22 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 14:41:50 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

bool	move_up(t_env *e)
{
	size_t	row;
	size_t	col;
	size_t	i;
	bool	ret;

	ret = false;
	col = -1;
	while (++col < e->size)
	{
		i = 0;
		while (i < e->size && e->map[i][col])
			i++;
		row = 0;
		while (i < e->size && ++row < e->size)
		{
			if (e->map[row][col] && i < row)
			{
				e->map[i][col] = e->map[row][col];
				e->map[row][col] = 0;
				i++;
				ret = true;
			}
		}
	}
	return (ret);
}

bool	move_down(t_env *e)
{
	size_t	row;
	size_t	col;
	size_t	i;
	bool	ret;

	ret = false;
	col = -1;
	while (++col < e->size)
	{
		i = e->size - 1;
		while (i + 1> 0 && e->map[i][col])
			i--;
		row = e->size - 1;
		while (i + 1 > 0 && --row + 1 > 0)
		{
			if (e->map[row][col] && i > row)
			{
				e->map[i][col] = e->map[row][col];
				e->map[row][col] = 0;
				i--;
				ret = true;
			}
		}
	}
	return (ret);
}

bool	move_left(t_env *e)
{
	if (e->size > 0)
		return (true);
	return (false);
}

bool	move_right(t_env *e)
{
	if (e->size > 0)
		return (true);
	return (false);
}
