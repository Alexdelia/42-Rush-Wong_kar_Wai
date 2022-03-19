/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 11:26:19 by adelille         ###   ########.fr       */
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

bool	play(t_env *e)
{
	while (!lost(e))
	{
		e->key = 0;
		while (!is_arrow(e->key) && !is_exit(e->key))
		{
			e->key = getch();
			if (e->key == KEY_RESIZE)
				resize(e);
		}
		if (is_exit(e->key))
			break ;
		if (key_handle(e)) // handle arrow
		{
			// only if a move occurred
			if (!insert(e))
				return (false);
			// clear maybe
			print_map(e); // with score and print win if win
		}
	}
	return (true);
}

int	main(void)
{
	t_env	e;

	if (!init(&e))
		return (end(&e, 1));
	if (!menu(&e)) // choosing size of board
		return (end(&e, 2));
	// clear maybe
	print_map(&e); // with score and print win if win
	if (!play(&e))
		return (end(&e, 4));
	if (e.state == STATE_LOST)
	{
		mvprintw(e.row - 2, (e.col - ft_strlen(MSG_LOST)) / 2, MSG_LOST);
		e.key = getch();
		while (is_arrow(e.key))
			e.key = getch();
	}
	// bonus: ask for pseudo and save score
	if (!save_score(&e))
		return (end(&e, 5));
	return (end(&e, 0));
}
