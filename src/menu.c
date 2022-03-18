/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:19:51 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 19:33:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	init_map(t_env *e)
{
	size_t	i;

	e->map = (size_t **)malloc(sizeof(size_t *) * (e->size + 1));
	if (!e->map)
		return (false);
	i = 0;
	while (i < e->size)
	{
		e->map[i] = (size_t *)malloc(sizeof(size_t) * (e->size + 1));
		if (!e->map[i])
		{
			free_map(e);
			return (false);
		}
		ft_bzero_st(e->map[i], e->size);
		i++;
	}
	e->map[i] = NULL;
	insert(e);
	insert(e);
	return (true);
}

bool	choose_play(t_env *e)
{
	clear();
	print_frame(e, COLOR_PAIR(CP_PLAY));
	e->key = 0;
	attrset(A_BOLD);
	while (e->size < MIN_BOARD || e->size > MAX_BOARD)
	{
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

bool	menu(t_env *e)
{
	e->key = 's';
	while (e->key == 's' || e->key == 'S')
	{
		clear();
		print_menu(e);
		move((e->row - 1) / 2 + 3, e->col / 2 - 2);
		e->key = getch();
		if (e->key == 'p' || e->key == 'P' || e->key == '\n')
		{
			if (!choose_play(e))
				return (false);
		}
		else if (e->key == 's' || e->key == 'S')
			choose_score(e);
		else
			return (false);
	}
	clear();
	curs_set(0);
	return (init_map(e));
}
