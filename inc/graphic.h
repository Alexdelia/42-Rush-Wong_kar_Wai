/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:13:13 by adelille          #+#    #+#             */
/*   Updated: 2022/03/19 11:25:37 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# ifndef NO_UNICODE
#  define NO_UNICODE	0
#  define MSG_PLAY		"PLAY🎮"
#  define MSG_EXIT		"EXIT✗"
# else
#  define MSG_WON		"YOU WON"
#  define MSG_LOST		"YOU LOST"
#  define MSG_PLAY		"PLAY"
#  define MSG_SCORE		"HIGHSCORE"
#  define MSG_EXIT		"EXIT"
#  define MSG_CUR_SCORE	"SCORE"
# endif


# define CP_RED			1
# define CP_GREEN		3
# define CP_MENU		5
# define CP_PLAY		6

# define SYMBOL_0		" "
# define SYMBOL_2		"○"
# define SYMBOL_4		"⊚"
# define SYMBOL_8		"⊝"
# define SYMBOL_16		"⊕"
# define SYMBOL_32		"⊘"
# define SYMBOL_64		"⊗"
# define SYMBOL_128		"⊛"
# define SYMBOL_256		"⬠"
# define SYMBOL_512		"⬡"
# define SYMBOL_1024	"⏣"
# define SYMBOL_2048	"א"
# define SYMBOL_4096	"∞"

# define COLOR_0		206
# define COLOR_2		207
# define COLOR_4		208
# define COLOR_8		209
# define COLOR_16		210
# define COLOR_32		211
# define COLOR_64		212
# define COLOR_128		213
# define COLOR_256		214
# define COLOR_512		215
# define COLOR_1024		216
# define COLOR_2048		217
# define COLOR_4096		218

/*
# define COLOR_B_0		219
# define COLOR_B_2		220
# define COLOR_B_4		221
# define COLOR_B_8		222
# define COLOR_B_16		223
# define COLOR_B_32		224
# define COLOR_B_64		225
# define COLOR_B_128	226
# define COLOR_B_256	227
# define COLOR_B_512	228
# define COLOR_B_1024	229
# define COLOR_B_2048	230
# define COLOR_B_4096	231
*/

#endif
