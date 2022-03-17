/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:47:54 by adelille          #+#    #+#             */
/*   Updated: 2022/03/17 16:45:17 by adelille         ###   ########.fr       */
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
}			t_env;

// function in process order
int		end(t_env *e, const int ret);

// key handling (key.c)
bool	resize(t_env *e);

// utils
bool	is_exit(const int key);
bool	valid_size(t_env *e);
void	pmw(t_env *e, const char *text);

#endif
