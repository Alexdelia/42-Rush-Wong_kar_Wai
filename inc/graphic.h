/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:13:13 by adelille          #+#    #+#             */
/*   Updated: 2022/03/20 14:17:03 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# ifndef NO_UNICODE
#  define NO_UNICODE	0
#  define MSG_PLAY		"PLAY🎮"
#  define MSG_EXIT		"EXIT✗"
#  define MSG_WON		"🎉 WON 🎉"
#  define MSG_LOST		"               ( ཀ ʖ̯ ཀ)  GAMEOVER  ლ(ಠ_ಠლ)"
# else
#  define MSG_PLAY		"PLAY "
#  define MSG_EXIT		"EXIT "
#  define MSG_WON		"WON"
#  define MSG_LOST		"GAMEOVER"
# endif

# define MSG_SCORE		"HIGHSCORE"
# define MSG_CUR_SCORE	"SCORE"

# define C_LOW_GREEN	232

# define CP_RED			1
# define CP_GREEN		3
# define CP_MENU		5
# define CP_PLAY		6
# define CP_BOARD		7
# define CP_SCORE		9
# define CP_EXIT		10

# define COLOR_F_0		206
# define COLOR_F_2		207
# define COLOR_F_4		208
# define COLOR_F_8		209
# define COLOR_F_16		210
# define COLOR_F_32		211
# define COLOR_F_64		212
# define COLOR_F_128	213
# define COLOR_F_256	214
# define COLOR_F_512	215
# define COLOR_F_1024	216
# define COLOR_F_2048	217
# define COLOR_F_4096	218

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

void	print_val_2(const int row, const int col);
void	print_val_4(const int row, const int col);
void	print_val_8(const int row, const int col);
void	print_val_16(const int row, const int col);
void	print_val_32(const int row, const int col);
void	print_val_64(const int row, const int col);
void	print_val_128(const int row, const int col);
void	print_val_256(const int row, const int col);
void	print_val_512(const int row, const int col);
void	print_val_1024(const int row, const int col);
void	print_val_2048(const int row, const int col);
void	print_val_4096(const int row, const int col);

#endif
