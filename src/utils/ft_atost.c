/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:32:59 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 16:42:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

size_t	ft_atost(char *str)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

char	*ft_sttoa(size_t n)
{
	char	*str;
	size_t	len;

	len = ft_stlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = (n / 10);
	}
	return (str);
}
