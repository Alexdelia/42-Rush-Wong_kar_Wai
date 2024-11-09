/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:19:51 by adelille          #+#    #+#             */
/*   Updated: 2022/03/26 18:24:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

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
	e->key = 0;
	while (e->size < MIN_BOARD || e->size > MAX_BOARD)
	{
		clear();
		print_frame(e, CP_PLAY);
		if (e->size != 0)
		{
			attrset(A_BOLD | COLOR_PAIR(CP_EXIT));
			mvprintw(e->row - 2, 2, "MIN: %d  MAX: %d", MIN_BOARD, MAX_BOARD);
		}
		attrset(A_BOLD | COLOR_PAIR(CP_PLAY));
		pmw(e, "board size: ");
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
	return (attrset(A_NORMAL), true);
}

static bool	menu_key_handle(t_env *e)
{
	move((e->row - 1) / 2 + 3, e->col / 2 - 2);
	e->key = getch();
	if (e->key == 'p' || e->key == 'P' || e->key == '\n')
	{
		if (!choose_play(e))
			return (false);
	}
	else if (e->key == 's' || e->key == 'S')
	{
		if (!choose_score(e))
			return (false);
	}
	else if (e->key == KEY_RESIZE)
	{
		if (!resize(e))
			return (false);
	}
	else
		return (false);
	return (true);
}

bool	menu(t_env *e)
{
	e->key = 's';
	while (e->key == 's' || e->key == 'S' || e->key == KEY_RESIZE)
	{
		clear();
		print_menu(e);
		if (!menu_key_handle(e))
			return (false);
	}
	clear();
	curs_set(0);
	return (init_map(e));
}
