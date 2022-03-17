/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:16:57 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 21:52:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

void	free_map(t_env *e)
{
	size_t	i;

	i = 0;
	while (i < e->size)
	{
		free(e->map[i]);
		i++;
	}
	free(e->map);
	e->map = NULL;
}

int	end(t_env *e, const int ret)
{
	endwin();
	if (e->map)
		free_map(e);
	return (ret);
}
