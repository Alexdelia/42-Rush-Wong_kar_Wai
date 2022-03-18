/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:53:46 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 23:49:53 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wkw.h"

static size_t	ft_strcpy_wkw(char *dst, const char *src, const size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

static void	save_score_from_file(t_score *s,
		char *file, const size_t size)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	s[0].score = 0;
	while (i < size && index < MAX_READ_SCORE)
	{
		s[index].score = ft_atost(&file[i]);
		while (file[i] != ' ')
			i++;
		i++;
		s[index].top = ft_atost(&file[i]);
		while (file[i] != ' ')
			i++;
		i++;
		ft_strcpy_wkw(s[index].pseudo, &file[i], size - i);
		while (i < size && file[i] && file[i] != '\n')
			i++;
		i++;
		index++;
		s[index].score = 0;
	}
}

bool	read_score(t_score *s)
{
	char	*file;
	size_t	size;
	int		fd;

	fd = open(SCORE_PATH, O_RDONLY);
	if (fd < 0)
		return (false);
	file = gal(fd, &size, TRUE);
	if (!file)
		return (false);
	mvprintw(0, 0, "|%ld|%s|", size, file);
	getch();
	save_score_from_file(s, file, size);
	free(file);
	close(fd);
	return (true);
}

static size_t	index_big(t_score *s, const size_t big)
{
	size_t	i;
	size_t	local_big;
	size_t	index_big;

	local_big = 0;
	index_big = 0;
	i = 0;
	while (i < MAX_READ_SCORE && s[i].score > 0)
	{
		if (s[i].score > local_big && s[i].score < big)
		{
			local_big = s[i].score;
			index_big = i;
		}
		i++;
	}
	if (local_big == 0)
		return (i);
	return (index_big);
}

void	sort_score(t_score *s, size_t *sort)
{
	size_t	i;
	size_t	big;

	i = 0;
	big = ULONG_MAX;
	while (i < MAX_READ_SCORE && big > 0)
	{
		sort[i] = index_big(s, big);
		big = s[sort[i]].score;
		i++;
	}
	sort[i] = i;
}
