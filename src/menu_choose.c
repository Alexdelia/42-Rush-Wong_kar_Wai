/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_choose.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:19:09 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 17:29:41 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

bool	choose_play(t_env *e)
{
	clear();
	e->key = 0;
	attrset(A_BOLD);
	while (e->size < MIN_BOARD || e->size > MAX_BOARD)
	{
		clear();
		if (e->size != 0)
			mvprintw(e->row - 2, 2,
				"size of board should be between %d and %d",
				MIN_BOARD, MAX_BOARD); //
		pmw(e, "please enter size of board: ");
		e->key = getch();
		if (is_exit(e->key))
			return (false);
		else if (e->key == KEY_RESIZE)
		{
			e->size = 0;
			if (!resize(e))
				return (false);
		}
		else
			e->size = (char)e->key - '0';
	}
	attrset(A_NORMAL);
	return (true);
}

bool	choose_score(t_env *e)
{
	clear();
	pmw(e, "SCORE");
	getch();
	return (true);
}
