/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuse.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:03:22 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 14:33:46 by adelille         ###   ########.fr       */
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
			if (e->map[row][col] == e->map[row + 1][col])
			{
				e->map[row][col] += e->map[row + 1][col];
				e->map[row + 1][col] = 0;
				ret = true;
			}
		}
	}
	return (ret);
}

bool	fuse_down(t_env *e)
{
	if (e->size > 0)
		return (true);
	return (false);
}

bool	fuse_left(t_env *e)
{
	if (e->size > 0)
		return (true);
	return (false);
}

bool	fuse_right(t_env *e)
{
	if (e->size > 0)
		return (true);
	return (false);
}
