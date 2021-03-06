/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:52:42 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 11:48:16 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

void	print_val_64(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "   ┌╴╷╷   ");
	mvaddstr(row + 2, col, "   ├┐└┤   ");
	mvaddstr(row + 3, col, "   └┘ ╵   ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_128(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "   ╷╶┐┌┐  ");
	mvaddstr(row + 2, col, "   │┌┘├┤  ");
	mvaddstr(row + 3, col, "   ╵└╴└┘  ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_256(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "  ╶┐┌┐┌╴  ");
	mvaddstr(row + 2, col, "  ┌┘└┐├┐  ");
	mvaddstr(row + 3, col, "  └╴└┘└┘  ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_512(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "  ┌┐ ╷╶┐  ");
	mvaddstr(row + 2, col, "  └┐ │┌┘  ");
	mvaddstr(row + 3, col, "  └┘ ╵└╴  ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_1024(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, "  ╷┌┐╶┐╷╷ ");
	mvaddstr(row + 2, col, "  │││┌┘└┤ ");
	mvaddstr(row + 3, col, "  ╵└┘└╴ ╵ ");
	mvaddstr(row + 4, col, "          ");
}
