/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:31:34 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 14:02:57 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	init(t_env *e)
{
	e->map = NULL;
	e->size = 0;
	e->score = 0;
	setlocale(LC_ALL, "");
	srand(time(NULL));
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	if (!init_colors())
		return (false);
	if (!resize(e))
		return (false);
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
	while (!lost(&e))
	{
		e.key = 0;
		while (!is_arrow(e.key) && !is_exit(e.key))
		{
			e.key = getch();
			if (e.key == KEY_RESIZE)
				resize(&e);
		}
		if (is_exit(e.key))
			break ;
		if (key_handle(&e)) // handle arrow
		{
			// only if a move occurred
			if (!insert(&e))
				return (end(&e, 4));
			// clear maybe
			print_map(&e); // with score and print win if win
			// might add a refresh in print_map
		}
	}
	// bonus: ask for pseudo and save score
	return (end(&e, 0));
}
