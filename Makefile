# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2022/03/21 17:55:25 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	2048
#CC = 	clang
CC =	cc
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
CFLAGS +=	-g3
# CFLAGS +=	-O2
# CFLAGS +=	-fsanitize=address

#CFLAGS +=	-DNO_UNICODE=1

#NCFLAGS =	-lncurses
NCFLAGS =	-std=c99
NCFLAGS +=	$(shell ncursesw5-config --cflags --libs)
#NCFLAGS +=	-D_DEFAULT_SOURCE -D_XOPEN_SOURCE=600 -Wl,-Bsymbolic-functions -lncursesw -ltinfo
#NCFLAGS +=	--disable-leaks

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	LIB		#

LIBPATH =	./libft/
LIBNAME =	$(LIBPATH)libft.a
LIBINC =	-I$(LIBPATH)

# **************************************************************************** #
#	SRCS	#

SRCSPATH =	./src/
OBJSPATH =	./obj/
INC =		./inc/

SRCS =		$(wildcard $(SRCSPATH)*.c) $(wildcard $(SRCSPATH)**/*.c)
SRCSNAME =	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME =	$(SRCSNAME:.c=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))

# *************************************************************************** #

define	progress_bar
	@i=0
	@while [[ $$i -le $(words $(SRCS)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	@printf "$(B)]\r[$(D)"
endef

# *************************************************************************** #
#	RULES	#

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	$(CC) $(CFLAGS) -MMD -MP -I$(INC) -c $< -o $@
	@printf "$(B)$(GRE)█$(D)"

all:		launch $(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"

test:		all
	@./$(NAME)

launch:
	$(call progress_bar)

$(NAME):	$(OBJS) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) -o $(NAME) $(NCFLAGS)

$(LIBNAME):
	@printf "$(D)$(B)$(BLU)\n$(NAME) objects compiled\n\n$(D)"
	@$(MAKE) -C $(LIBPATH)
	
clean:
	@$(RM) $(OBJSPATH)
	@$(MAKE) clean -C $(LIBPATH)

fclean:
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBPATH)

re:			fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re launch test

# **************************************************************************** #
