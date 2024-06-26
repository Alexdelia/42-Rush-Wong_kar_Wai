# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2022/03/18 23:13:09 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
#CC = 	clang
CC =	cc
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
#CFLAGS +=	-O2
#CFLAGS +=	-g3
#CFLAGS +=	-fsanitize=address

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
#	SRCS	#

SRCSPATH =	./src/
OBJSPATH =	./obj/
INC =		./inc/

#SRCSNAME =	I-O/ft_ps.c I-O/ft_putchar_fd.c I-O/ft_putendl_fd.c \
				I-O/ft_putnbr_fd.c I-O/ft_putstr_fd.c I-O/ft_pn.c \
				str/ft_atoi.c str/ft_atol.c str/ft_atof.c str/ft_itoa.c \
				str/ft_bzero.c str/ft_split.c str/ft_strchr.c \
				str/ft_strcmp.c str/ft_strdup.c str/ft_strjoin.c str/ft_strlcat.c \
				str/ft_strlcpy.c str/ft_strcpy.c \
				str/ft_strlen.c str/ft_strmapi.c str/ft_strncmp.c \
				str/ft_strnstr.c str/ft_strrchr.c str/ft_strtrim.c str/ft_substr.c \
				str/ft_tolower.c str/ft_toupper.c \
				nbr/ft_nbrlen.c nbr/ft_abs.c \
				nbr/ft_is_prime.c nbr/ft_next_prime.c nbr/ft_prev_prime.c \
				mem/ft_calloc.c mem/ft_memccpy.c mem/ft_memchr.c mem/ft_memcmp.c \
				mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c \
				lst/ft_lstadd_back.c lst/ft_lstadd_front.c lst/ft_lstclear.c lst/ft_lstdelone.c \
				lst/ft_lstiter.c lst/ft_lstlast.c lst/ft_lstmap.c lst/ft_lstnew.c lst/ft_lstsize.c \
				bool_detect/ft_isalnum.c bool_detect/ft_isalpha.c bool_detect/ft_isascii.c \
				bool_detect/ft_isdigit.c bool_detect/ft_isprint.c

#SRCS =		$(addprefix $(SRCSPATH), $(SRCSNAME))
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

all:		launch $(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"

launch:
	$(call progress_bar)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@printf "$(B)$(GRE)█$(D)"
	
clean:
	@$(RM) $(OBJSPATH)

fclean:		clean
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re launch

# **************************************************************************** #
