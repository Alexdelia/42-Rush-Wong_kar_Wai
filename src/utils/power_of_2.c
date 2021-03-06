/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:07:23 by adelille          #+#    #+#             */
/*   Updated: 2022/03/20 12:37:24 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

bool	power_of_2(const size_t n)
{
	size_t	i;

	i = 2;
	while (i < n && i < LONG_MAX)
		i <<= 1;
	return (i == n);
}
