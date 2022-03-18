/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:37:55 by adelille          #+#    #+#             */
/*   Updated: 2022/03/18 16:02:18 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/wkw.h"

bool	is_exit(const int key)
{
	return (key == 'q'
		|| key == KEY_BACKSPACE
		|| key == KEY_DC
		|| key == KEY_END
		|| key == KEY_EXIT
		|| key == KEY_ESCAPE
		|| key == KEY_CC
		|| key == KEY_CD);
}

bool	is_arrow(const int key)
{
	return (key == KEY_UP
		|| key == KEY_DOWN
		|| key == KEY_LEFT
		|| key == KEY_RIGHT
		|| key == 'w'
		|| key == 's'
		|| key == 'a'
		|| key == 'd');
}

/*bool	is_revert(const int key)
{
	return (key == 'r'
		|| key == 'e');
}*/
