/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:46:48 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 21:47:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

bool	lost(t_env *e)
{
	if (!empty_count(e->map, e->size))
		return (true);
	// need to do more check than that
	return (false);
}
