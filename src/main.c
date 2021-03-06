/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/03/20 14:41:43 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	init(t_env *e)
{
	e->map = NULL;
	e->size = 0;
	e->score = 0;
	e->state = STATE_NO;
	e->top = 2;
	if (WIN_VALUE < 0 || !power_of_2(WIN_VALUE))
		return (!ft_ps("ERROR: WIN_VALUE isn't a power of 2\n"));
	if (!NO_UNICODE)
		setlocale(LC_ALL, "");
	srand(time(NULL));
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	if (!init_colors())
		return (false);
	if (!resize(e))
		return (false);
	return (true);
}

static void	print_lost(t_env *e)
{
	attrset(A_BOLD | COLOR_PAIR(CP_EXIT));
	if ((size_t)e->col > ft_strlen(MSG_LOST) || NO_UNICODE)
		mvprintw(e->row - 2, (e->col - ft_strlen(MSG_LOST)) / 2, MSG_LOST);
	else
		mvprintw(e->row - 2, 0, &MSG_LOST[8]);
	attrset(A_NORMAL);
	e->key = getch();
	while (is_arrow(e->key))
		e->key = getch();
}

static bool	play(t_env *e)
{
	while (!lost(e))
	{
		e->key = 0;
		while (!is_arrow(e->key) && !is_exit(e->key))
		{
			e->key = getch();
			if (e->key == KEY_RESIZE)
			{
				if (!resize(e))
					return (false);
				clear();
				print_map(e);
			}
		}
		if (is_exit(e->key))
			break ;
		if (key_handle(e))
		{
			if (!insert(e))
				return (false);
			print_map(e);
		}
	}
	return (true);
}

int	main(void)
{
	t_env	e;

	if (!init(&e))
		return (end(&e, 1));
	if (!menu(&e))
		return (end(&e, 2));
	if (!resize(&e))
		return (end(&e, 3));
	clear();
	print_map(&e);
	if (!play(&e))
		return (end(&e, 4));
	if (e.state == STATE_LOST)
		print_lost(&e);
	if (e.key != KEY_RESIZE && !save_score(&e))
		return (end(&e, 5));
	return (end(&e, 0));
}
