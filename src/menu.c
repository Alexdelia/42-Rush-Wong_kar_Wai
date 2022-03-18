/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:19:51 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 17:38:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static void	ft_bzero_st(size_t *s, size_t n)
{
	if (!s)
		return ;
	while (--n)
		s[n] = 0;
	s[n] = 0;
}

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

static void	print_menu(t_env *e)
{
	//print_border(e, CP_MENU);
	attrset(A_BOLD | COLOR_PAIR(CP_PLAY));
	mvprintw((e->row - 1) / 2 - 1,
		(e->col - ft_strlen(MSG_PLAY)) / 2, MSG_PLAY);
	attrset(A_BOLD | COLOR_PAIR(get_color(2048)));
	mvprintw((e->row - 1) / 2,
		(e->col - ft_strlen(MSG_SCORE)) / 2 - 1, MSG_SCORE);
	attrset(A_BOLD | COLOR_PAIR(get_color(64)));
	mvprintw((e->row - 1) / 2 + 1,
		(e->col - ft_strlen(MSG_EXIT)) / 2, MSG_EXIT);
	move((e->row - 1) / 2 + 2, (e->col - ft_strlen("[p/s/q]")) / 2 - 1);
	attrset(A_NORMAL);
	addch('[');
	attrset(COLOR_PAIR(CP_PLAY));
	addch('p');
	attrset(A_NORMAL);
	addch('/');
	attrset(COLOR_PAIR(get_color(2048)));
	addch('s');
	attrset(A_NORMAL);
	addch('/');
	attrset(COLOR_PAIR(get_color(64)));
	addch('q');
	attrset(A_NORMAL);
	addch(']');
}

bool	menu(t_env *e)
{
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
	clear();
	curs_set(0);
	return (init_map(e));
}
