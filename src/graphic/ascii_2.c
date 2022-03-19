/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:02:07 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 11:48:33 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

void	print_val_2048(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, " ╶┐┌┐╷╷┌┐ ");
	mvaddstr(row + 2, col, " ┌┘││└┤├┤ ");
	mvaddstr(row + 3, col, " └╴└┘ ╵└┘ ");
	mvaddstr(row + 4, col, "          ");
}

void	print_val_4096(const int row, const int col)
{
	mvaddstr(row, col, "          ");
	mvaddstr(row + 1, col, " ╷╷┌┐┌┐┌╴ ");
	mvaddstr(row + 2, col, " └┤││└┤├┐ ");
	mvaddstr(row + 3, col, "  ╵└┘ ╵└┘ ");
	mvaddstr(row + 4, col, "          ");
}
