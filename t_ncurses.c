/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ncurses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:29:48 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 15:27:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string.h>
#include <stdbool.h>

#define KEY_ESCAPE	27
#define KEY_CC		3
#define KEY_CD		4
#define KEY_Q		113

// https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/

// https://www.gnu.org/software/guile-ncurses/manual/html_node/Getting-characters-from-the-keyboard.html
bool	is_exit(const int key)
{
	return (key == KEY_Q
			|| key == KEY_BACKSPACE
			|| key == KEY_DC
			|| key == KEY_END
			|| key == KEY_EXIT
			|| key == KEY_ESCAPE
			|| key == KEY_CC
			|| key == KEY_CD);
}

int	main(void)
{
	char	txt[] = "Hello world";
	int		row;
	int		col;
	int		key;

	initscr();
	raw(); // cbreak();
	noecho();
	keypad(stdscr, TRUE);
	// KEY_RESIZE

	key = 0;
	while (!is_exit(key))
	{
		clear();
		getmaxyx(stdscr, row, col);
		mvprintw(row / 2, (col - strlen(txt)) / 2, txt);
		mvprintw(0, 0, "col: %d\nrow: %d\nkey: %d (%c)", col, row, key, (char)key);
		// refresh();
		key = getch(); // refresh is called before getch();
	}

	endwin();

	return (0);
}
