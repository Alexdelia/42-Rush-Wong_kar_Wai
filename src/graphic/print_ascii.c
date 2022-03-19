/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:07:28 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 12:27:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

static void	print_ascii_small(const size_t val, const int row, const int col)
{
	if (val == 2)
		print_val_2(row, col);
	else if (val == 4)
		print_val_4(row, col);
	else if (val == 8)
		print_val_8(row, col);
	else if (val == 16)
		print_val_16(row, col);
	else if (val == 32)
		print_val_32(row, col);
	else
		print_val_64(row, col);
}

static void	print_ascii_big(const size_t val, const int row, const int col)
{
	if (val == 128)
		print_val_128(row, col);
	else if (val == 256)
		print_val_256(row, col);
	else if (val == 512)
		print_val_512(row, col);
	else if (val == 1024)
		print_val_1024(row, col);
	else if (val == 2048)
		print_val_2048(row, col);
	else
		print_val_4096(row, col);
}

void	print_ascii(const size_t val, const int row, const int col)
{
	if (val <= 64)
		print_ascii_small(val, row, col);
	else
		print_ascii_big(val, row, col);
}
