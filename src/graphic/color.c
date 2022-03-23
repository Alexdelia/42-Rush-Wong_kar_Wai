/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:42:03 by adelille          #+#    #+#             */
/*   Updated: 2022/03/23 12:09:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

int	get_color(const int val)
{
	if (val == 0)
		return (1);
	else if (val <= 128)
		return (val);
	else if (val >= 4096)
		return (144);
	else
		return ((val / 256) + 128);
}

void	main_colors(void)
{
	init_color(C_LOW_GREEN, r(0x34), r(0x8c), r(0x46));
	init_color(C_WINDOW, r(0x31), r(0x28), r(0x21));
	init_color(C_BOARD, r(0x84), r(0x79), r(0x6b));
}

void	main_pairs(void)
{
	init_pair(CP_RED, COLOR_RED, C_WINDOW);
	init_pair(CP_GREEN, COLOR_GREEN, C_WINDOW);
	init_pair(CP_MENU, COLOR_MAGENTA, C_WINDOW);
	init_pair(CP_PLAY, COLOR_GREEN, C_WINDOW);
	init_pair(CP_BOARD, C_WINDOW, C_BOARD);
	init_pair(CP_SCORE, COLOR_B_2048, C_WINDOW);
	init_pair(CP_EXIT, COLOR_B_64, C_WINDOW);
	init_pair(CP_WINDOW, COLOR_WHITE, C_WINDOW);
}
