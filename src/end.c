/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:16:57 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 16:47:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static void	free_map(size_t **map, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	end(t_env *e, const int ret)
{
	endwin();
	if (e->map)
		free_map(e->map, e->size);
	return (ret);
}
