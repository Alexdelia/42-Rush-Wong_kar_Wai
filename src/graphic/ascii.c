/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 09:45:52 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 10:14:30 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

void	print_val_2(const int color, const int row, const int col)
{
	attrset(COLOR_PAIR(color));
	mvaddstr(row, col, "_11223344_");
	mvaddstr(row + 1, col, "    ╶┐");
	mvaddstr(row + 2, col, "    ┌┘");
	mvaddstr(row + 3, col, "    └╴");
	attrset(A_NORMAL);
}

void	print_val_4(const int color, const int row, const int col)
{
	attrset(COLOR_PAIR(color));
	mvaddstr(row, col, "_11223344_");
	mvaddstr(row + 1, col, "    ╷╷");
	mvaddstr(row + 2, col, "    └┤");
	mvaddstr(row + 3, col, "     ╵");
	attrset(A_NORMAL);
}

void	print_val_2048(const int color, const int row, const int col)
{
	attrset(COLOR_PAIR(color));
	mvaddstr(row, col, "_11223344_");
	mvaddstr(row + 1, col, " ╶┐┌┐╷╷┌┐");
	mvaddstr(row + 2, col, " ┌┘││└┤├┤");
	mvaddstr(row + 3, col, " └╴└┘ ╵└┘");
	attrset(A_NORMAL);
}
