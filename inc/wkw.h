/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkw.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:47:54 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 18:17:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WKW_H
# define WKW_H

# include "../libft/inc/libft.h"
# include "graphic.h"

# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <locale.h>
# include <time.h>
# include <fcntl.h>

# ifndef WIN_VALUE
#  define WIN_VALUE	2048
# endif

# define STATE_NO	0
# define STATE_WON	1
# define STATE_LOST	2

# define MIN_ROW	12
# define MIN_COL	20 // not right

# define MIN_BOARD	4
# define MAX_BOARD	5

# ifndef SCORE_PATH
#  define SCORE_PATH	"./score.txt"
# endif

# define KEY_ESCAPE	27
# define KEY_CC		3
# define KEY_CD		4

// https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/

// https://www.gnu.org/software/guile-ncurses/manual/html_node/Getting-characters-from-the-keyboard.html

typedef struct s_env
{
	int		row;	// window row
	int		col;	// window column
	int		key;	// key pressed
	int		state;	// state of game (none, won, lost)
	size_t	**map;
	size_t	size;	// size of map (4x4, 5x5, ...)
	size_t	score;
	size_t	top;	// biggest value on board
}			t_env;

// function in process order
bool	menu(t_env *e);
bool	choose_play(t_env *e);
void	choose_score(t_env *e);
bool	lost(t_env *e);
bool	save_score(t_env *e);
int		end(t_env *e, const int ret);

// color
bool	init_colors(void);
int		get_color(const int val);

// key handling (key.c)
bool	key_handle(t_env *e);
bool	resize(t_env *e);
bool	is_exit(const int key);
bool	is_arrow(const int key);
bool	is_revert(const int key);

// move, fuse
bool	move_up(t_env *e);
bool	move_down(t_env *e);
bool	move_left(t_env *e);
bool	move_right(t_env *e);
bool	fuse_up(t_env *e);
bool	fuse_down(t_env *e);
bool	fuse_left(t_env *e);
bool	fuse_right(t_env *e);

// map
bool	insert(t_env *e);
size_t	empty_count(size_t **map, const size_t size);
void	print_map(t_env *e);
void	print_symbol(const size_t val);
void	free_map(t_env *e);

// utils
bool	valid_size(t_env *e);
void	pmw(t_env *e, const char *text);
size_t	ft_stlen(size_t n);
bool	can_fuse_row(size_t **map, const size_t size);
bool	can_fuse_col(size_t **map, const size_t size);
bool	power_of_2(const size_t n);
size_t	ft_atost(char *str);
char	*ft_sttoa(size_t n);
void	print_frame(t_env *e, const int color);

#endif
