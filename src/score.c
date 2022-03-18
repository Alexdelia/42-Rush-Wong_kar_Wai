/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:55:46 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 16:51:53 by adelille         ###   ########.fr       */
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
	printw(" .");
	refresh();
	tmp = ft_sttoa(e->top);
	if (!tmp)
		return (false);
	ft_putstr_fd(tmp, fd);
	free(tmp);
	ft_putstr_fd(" ", fd);
	printw(" .");
	refresh();
	ft_putstr_fd(pseudo, fd);
	ft_putstr_fd("\n", fd);
	attrset(COLOR_PAIR(CP_GREEN));
	printw("✓");
	attrset(A_NORMAL);
	refresh();
	getch(); //
	return (true);
}

bool	save_score(t_env *e)
{
	int		fd;
	char	pseudo[101];
	size_t	i;

	clear();
	mvprintw(1, (e->col - (ft_strlen("SCORE: ") + ft_stlen(e->score))) / 2,
		"SCORE: %ld\n", e->score);
	pmw(e, "do you want to save your score [y/n]");
	e->key = getch();
	if (e->key != 'y' && e->key != 'Y')
		return (true);
	clear();
	echo();
	pmw(e, "What is your pseudo: ");
	e->key = getch();
	i = 0;
	while (i < 100 && e->key != KEY_ENTER)
	{
		if (i > 0 && e->key == KEY_BACKSPACE)
			i--;
		else if (ft_isprint(e->key))
		{
			pseudo[i] = (char)e->key;
			i++;
		}
		else if (is_exit(e->key))
			break ;
		e->key = getch();
	}
	printw(" .");
	refresh();
	fd = open(SCORE_PATH, O_CREAT | O_RDWR | O_APPEND, 0664);
	if (fd < 0)
		return (false);
	return (write_score(e, pseudo, fd));
}
