/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:07:28 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 13:09:39 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

static void	print_symbol_small(const size_t val)
{
	if (val == 0)
		printw(SYMBOL_0);
	else if (val == 2)
		printw(SYMBOL_2);
	else if (val == 4)
		printw(SYMBOL_4);
	else if (val == 8)
		printw(SYMBOL_8);
	else if (val == 16)
		printw(SYMBOL_16);
	else if (val == 32)
		printw(SYMBOL_32);
	else
		printw(SYMBOL_64);
}

static void	print_symbol_big(const size_t val)
{
	if (val == 128)
		printw(SYMBOL_128);
	else if (val == 256)
		printw(SYMBOL_256);
	else if (val == 512)
		printw(SYMBOL_512);
	else if (val == 1024)
		printw(SYMBOL_1024);
	else if (val == 2048)
		printw(SYMBOL_2048);
	else if (val == 4096)
		printw(SYMBOL_4096);
	else
		printw("%ld", val);
}

void	print_symbol(const size_t val)
{
	if (val <= 64)
		print_symbol_small(val);
	else
		print_symbol_big(val);
}
