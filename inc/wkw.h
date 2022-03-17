/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:47:54 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 20:28:23 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WKW_H
# define WKW_H

# include "../libft/inc/libft.h"

# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <locale.h>
# include <time.h>

# ifndef WIN_VALUE
#  define WIN_VALUE	2048
# endif

# define MIN_ROW	12
# define MIN_COL	10

# define MIN_BOARD	4
# define MAX_BOARD	5

# define KEY_ESCAPE	27
# define KEY_CC		3
# define KEY_CD		4
# define KEY_Q		113

# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100

# define KEY_R		114
# define KEY_E		101

# define CP_RED		1

// https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/

// https://www.gnu.org/software/guile-ncurses/manual/html_node/Getting-characters-from-the-keyboard.html

typedef struct s_env
{
	int		row;
	int		col;
	int		key;
	size_t	**map;
	size_t	size;
	size_t	score;
	size_t	row_last_insert;
	size_t	col_last_insert;
}			t_env;

// function in process order
bool	menu(t_env *e);
int		end(t_env *e, const int ret);

// key handling (key.c)
bool	resize(t_env *e);

// map
bool	insert(t_env *e);
size_t	empty_count(size_t **map, const size_t size);
void	free_map(size_t **map, const size_t size);

// utils
bool	is_exit(const int key);
bool	is_arrow(const int key);
bool	valid_size(t_env *e);
void	pmw(t_env *e, const char *text);

#endif
