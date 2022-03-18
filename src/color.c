/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:42:03 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 23:02:13 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

int	get_color(const int val)
{
	if (val <= 128)
		return (val);
	else if (val >= 4096)
		return (144);
	else
		return ((val / 256) + 128);
}

static int	r(const int val)
{
	return ((val * 1000) / 256);
}

static void	create_colors(void)
{
	init_color(COLOR_0, r(0x20), r(0x20), r(0x20));
	init_color(COLOR_2, r(0xee), r(0xf4), r(0xfa));
	init_color(COLOR_4, r(0xed), r(0xe0), r(0xc8));
	init_color(COLOR_8, r(0xf2), r(0xb1), r(0x79));
	init_color(COLOR_16, r(0xf5), r(0x95), r(0x63));
	init_color(COLOR_32, r(0xf6), r(0x7c), r(0x5f));
	init_color(COLOR_64, r(0xf6), r(0x5e), r(0x3b));
	init_color(COLOR_128, r(0xed), r(0xcf), r(0x72));
	init_color(COLOR_256, r(0xed), r(0xcc), r(0x61));
	init_color(COLOR_512, r(0xed), r(0xc8), r(0x50));
	init_color(COLOR_1024, r(0xed), r(0xc5), r(0x3f));
	init_color(COLOR_2048, r(0xed), r(0xc2), r(0x20));
	init_color(COLOR_4096, r(0x3c), r(0x3a), r(0x32));
}

static void	init_pairs(void)
{
	init_pair(CP_RED, COLOR_RED, COLOR_BLACK);
	init_pair(CP_GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(CP_MENU, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(CP_PLAY, COLOR_GREEN, COLOR_BLACK);
	init_pair(0, COLOR_0, COLOR_BLACK);
	init_pair(2, COLOR_2, COLOR_BLACK);
	init_pair(4, COLOR_4, COLOR_BLACK);
	init_pair(8, COLOR_8, COLOR_BLACK);
	init_pair(16, COLOR_16, COLOR_BLACK);
	init_pair(32, COLOR_32, COLOR_BLACK);
	init_pair(64, COLOR_64, COLOR_BLACK);
	init_pair(128, COLOR_128, COLOR_BLACK);
	init_pair(129, COLOR_256, COLOR_BLACK);
	init_pair(130, COLOR_512, COLOR_BLACK);
	init_pair(132, COLOR_1024, COLOR_BLACK);
	init_pair(136, COLOR_2048, COLOR_BLACK);
	init_pair(144, COLOR_4096, COLOR_BLACK);
}

bool	init_colors(void)
{
	if (!has_colors())
		return (!ft_ps("Error: your terminal doesn't support colors\n"));
	else if (!can_change_color())
		return (!ft_ps("Error: terminal doesn't support color change\n"));
	start_color();
	create_colors();
	init_pairs();
	return (true);
}
