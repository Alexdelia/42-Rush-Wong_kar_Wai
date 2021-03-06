/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:45:52 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 15:06:19 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

void	print_val_2(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "    ╶┐    ");
	mvaddstr(row + 2, col, "    ┌┘    ");
	mvaddstr(row + 3, col, "    └╴    ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_4(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "    ╷╷    ");
	mvaddstr(row + 2, col, "    └┤    ");
	mvaddstr(row + 3, col, "     ╵    ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_8(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "    ┌┐    ");
	mvaddstr(row + 2, col, "    ├┤    ");
	mvaddstr(row + 3, col, "    └┘    ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_16(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "    ╷┌╴   ");
	mvaddstr(row + 2, col, "    │├┐   ");
	mvaddstr(row + 3, col, "    ╵└┘   ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_32(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "   ╶┐╶┐   ");
	mvaddstr(row + 2, col, "   ╶┤┌┘   ");
	mvaddstr(row + 3, col, "   ╶┘└╴   ");
	mvaddstr(row + 4, col, "          ");
}
