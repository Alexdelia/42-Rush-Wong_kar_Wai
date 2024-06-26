/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:25:16 by adelille          #+#    #+#             */
/*   Updated: 2024/06/16 13:51:05 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

void	pmw(t_env *e, const char *text)
{
	mvprintw((e->row - 1) / 2, (e->col - ft_strlen(text)) / 2, "%s", text);
}
