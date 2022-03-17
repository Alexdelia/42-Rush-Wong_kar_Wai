/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:08:09 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 16:47:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

bool	valid_size(t_env *e)
{
	if (e->size == 0)
		return (e->row >= MIN_ROW && e->col >= MIN_COL);
	return (e->row >= (int)e->size * 2 + 3 && e->col >= (int)e->size * 2 + 1);
}