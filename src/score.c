/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:55:46 by adelille          #+#    #+#             */
/*   Updated: 2022/05/10 17:27:58 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static bool	write_score(t_env *e, char *pseudo, const int fd)
{
	char	*tmp;

	tmp = ft_sttoa(e->score);
	if (!tmp)
		return (false);
	ft_putstr_fd(tmp, fd);
	free(tmp);
	ft_putstr_fd(" ", fd);
	tmp = ft_sttoa(e->top);
	if (!tmp)
		return (false);
	ft_putstr_fd(tmp, fd);
	free(tmp);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(pseudo, fd);
	ft_putstr_fd("\n", fd);
	close(fd);
	return (true);
}

static void	get_pseudo(t_env *e, char *pseudo)
{
	size_t	i;

	clear();
	print_frame(e, CP_MENU);
	echo();
	attrset(A_BOLD);
	pmw(e, "Enter your name: ");
	e->key = getch();
	i = 0;
	while (i < 100 && e->key != '\n')
	{
		if (i > 0 && e->key == KEY_BACKSPACE)
			i--;
		else if (ft_isprint(e->key))
		{
			pseudo[i] = (char)e->key;
			i++;
		}
		else if (is_exit(e->key) || e->key == KEY_RESIZE)
			break ;
		e->key = getch();
	}
	attrset(A_NORMAL);
	pseudo[i] = '\0';
}

bool	save_score(t_env *e)
{
	int		fd;
	char	pseudo[101];

	clear();
	print_frame(e, CP_SCORE);
	curs_set(1);
	attrset(A_BOLD | COLOR_PAIR(CP_SCORE));
	mvprintw(e->row / 2 - 3,
		(e->col - (ft_strlen(MSG_CUR_SCORE) + 1 + ft_stlen(e->score))) / 2,
		"%s %ld", MSG_CUR_SCORE, e->score);
	pmw(e, "do you want to save your score");
	attrset(A_BOLD);
	mvaddstr(e->row / 2 + 1, (e->col - 5) / 2, "[y/n]");
	move(e->row / 2 + 2, e->col / 2 - 1);
	attrset(A_NORMAL);
	e->key = getch();
	if (e->key != 'y' && e->key != 'Y' && e->key != '\n')
		return (true);
	get_pseudo(e, pseudo);
	fd = open(SCORE_PATH, O_CREAT | O_RDWR | O_APPEND, 0664);
	if (fd < 0)
		return (false);
	return (write_score(e, pseudo, fd));
}

static void	print_header_score(t_env *e)
{
	attrset(A_BOLD | A_UNDERLINE);
	mvprintw(2, 7, "PSEUDO");
	mvprintw(2, (e->col - ft_strlen("SCORE")) / 2 + 3, "SCORE");
	mvprintw(2, e->col - 8, "TOP");
	attrset(A_NORMAL);
}

bool	choose_score(t_env *e)
{
	t_score	s[MAX_READ_SCORE + 1];
	size_t	sort[MAX_READ_SCORE + 1];

	clear();
	curs_set(0);
	print_frame_score(e, CP_SCORE);
	print_header_score(e);
	if (!read_score(s))
		pmw(e, "NO SCORE");
	else
	{
		sort_score(s, sort);
		print_score(e, s, sort);
	}
	if (getch() == KEY_RESIZE)
	{
		if (!resize(e))
			return (false);
		if (!choose_score(e))
			return (false);
	}
	curs_set(1);
	return (true);
}
