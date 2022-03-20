/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:42:03 by adelille          #+#    #+#             */
/*   Updated: 2022/03/20 14:10:06 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

int	get_color(const int val)
{
	if (val <= 128)
		return (val);
	else if (val >= 4096)
		return (144);
	else
		return ((val / 256) + 128);
}

void	main_colors(void)
{
	init_color(C_LOW_GREEN, r(0x34), r(0x8c), r(0x46));
}

void	main_pairs(void)
{
	init_pair(CP_RED, COLOR_RED, COLOR_BLACK);
	init_pair(CP_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(CP_MENU, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(CP_PLAY, COLOR_GREEN, COLOR_BLACK);
	init_pair(CP_BOARD, COLOR_BLACK, C_LOW_GREEN);
	init_pair(CP_SCORE, COLOR_B_2048, COLOR_BLACK);
	init_pair(CP_EXIT, COLOR_B_64, COLOR_BLACK);
}
