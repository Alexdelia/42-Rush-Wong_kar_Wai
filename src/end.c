/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:16:57 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 19:38:20 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

void	free_map(size_t **map, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

int	end(t_env *e, const int ret)
{
	endwin();
	if (e->map)
		free_map(e->map, e->size);
	return (ret);
}
