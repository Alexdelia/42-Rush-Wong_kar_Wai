/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:33:38 by adelille          #+#    #+#             */
/*   Updated: 2022/03/23 11:59:46 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

int	r(const int val)
{
	return ((val * 1000) / 256);
}

static void	create_colors_front(void)
{
	init_color(COLOR_F_0, r(0x22), r(0x22), r(0x22));
	init_color(COLOR_F_2, r(0x22), r(0x22), r(0x22));
	init_color(COLOR_F_4, r(0x22), r(0x22), r(0x22));
	init_color(COLOR_F_8, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_16, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_32, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_64, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_128, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_256, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_512, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_1024, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_2048, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_4096, r(0x77), r(0x6e), r(0x65));
}

static void	create_colors_back(void)
{
	init_color(COLOR_B_0, r(0x94), r(0x8e), r(0x83));
	init_color(COLOR_B_2, r(0xee), r(0xf4), r(0xfa));
	init_color(COLOR_B_4, r(0xed), r(0xe0), r(0xc8));
	init_color(COLOR_B_8, r(0xf2), r(0xb1), r(0x79));
	init_color(COLOR_B_16, r(0xf5), r(0x95), r(0x63));
	init_color(COLOR_B_32, r(0xf6), r(0x7c), r(0x5f));
	init_color(COLOR_B_64, r(0xf6), r(0x5e), r(0x3b));
	init_color(COLOR_B_128, r(0xed), r(0xcf), r(0x72));
	init_color(COLOR_B_256, r(0xed), r(0xcc), r(0x61));
	init_color(COLOR_B_512, r(0xed), r(0xc8), r(0x50));
	init_color(COLOR_B_1024, r(0xed), r(0xc5), r(0x3f));
	init_color(COLOR_B_2048, r(0xed), r(0xc2), r(0x20));
	init_color(COLOR_B_4096, r(0x3c), r(0x3a), r(0x32));
}

static void	init_pairs(void)
{
	init_pair(CP_0, COLOR_F_0, COLOR_B_0);
	init_pair(2, COLOR_F_2, COLOR_B_2);
	init_pair(4, COLOR_F_4, COLOR_B_4);
	init_pair(8, COLOR_F_8, COLOR_B_8);
	init_pair(16, COLOR_F_16, COLOR_B_16);
	init_pair(32, COLOR_F_32, COLOR_B_32);
	init_pair(64, COLOR_F_64, COLOR_B_64);
	init_pair(128, COLOR_F_128, COLOR_B_128);
	init_pair(129, COLOR_F_256, COLOR_B_256);
	init_pair(130, COLOR_F_512, COLOR_B_512);
	init_pair(132, COLOR_F_1024, COLOR_B_1024);
	init_pair(136, COLOR_F_2048, COLOR_B_2048);
	init_pair(144, COLOR_F_4096, COLOR_B_4096);
}

bool	init_colors(void)
{
	if (!has_colors())
		return (!ft_ps("Error: your terminal doesn't support colors\n"));
	else if (!can_change_color())
		return (!ft_ps("Error: terminal doesn't support color change\n"));
	start_color();
	create_colors_front();
	create_colors_back();
	main_colors();
	main_pairs();
	init_pairs();
	bkgd(COLOR_PAIR(CP_WINDOW));
	return (true);
}
