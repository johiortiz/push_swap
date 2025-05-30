# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 02:19:39 by johyorti          #+#    #+#              #
#    Updated: 2024/10/09 21:10:02 by johyorti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
	
DEF_COLOR =		\033[0;39m
RED =			\033[0;91m
GREEN =			\033[0;92m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
BROWN =			\033[38;2;184;143;29m
PURPLE =         	\033[0;95m 

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_strncmp.c ft_memcmp.c \
				ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_atoi.c \
				ft_strrchr.c ft_strnstr.c ft_memset.c ft_memcpy.c ft_memmove.c \
				ft_bzero.c ft_memchr.c ft_calloc.c ft_strdup.c ft_strjoin.c \
				ft_strtrim.c ft_substr.c ft_split.c  ft_putchar_fd.c \
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c \
				ft_striteri.c ft_itoa.c  
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c  ft_lstiter_bonus.c ft_lstmap_bonus.c 

INCLUDE = libft.h

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c 
	@echo "${BLUE} ◎ $(BROWN)Compiling   ${MAGENTA}→   $(CYAN)$< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.c=.o}
BONUS_OBJECTS = ${BONUS:.c=.o}
HEADER = \
                          ****************************************************     \n \
                           ****************************************************     \n \
                           ****************************************************     \n \
                           ***     ██╗     ██╗██████╗ ███████╗████████╗     ***     \n \
                           ***     ██║     ██║██╔══██╗██╔════╝╚══██╔══╝     ***     \n \
                           ***     ██║     ██║██████╔╝█████╗     ██║        ***     \n \
                           ***     ██║     ██║██╔══██╗██╔══╝     ██║        ***     \n \
                           ***     ███████╗██║██████╔╝██║        ██║        ***     \n \
                           ***     ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝        ***     \n \
                    	   ****************************************************     \n \
                    	   ****************************************************     \n \
                           ****************************************************  


all : print_header $(NAME)

print_header:
	@echo "${PURPLE}$(HEADER)${DEF_COLOR}"

$(NAME): $(OBJS)
	@ar -rsc ${NAME} ${OBJS}
	@echo "\n$(GREEN) Created $(NAME) ✓ $(DEF_COLOR)\n"


bonus: ${OBJS} ${BONUS_OBJECTS}
	@ar -rsc $(NAME) $^
	@touch $@
	@echo "\n${GREEN} Bonus compiled successfully ✓ $(DEF_COLOR)\n"



clean:
	@${RM} ${OBJS} ${BONUS_OBJECTS}
	@echo "\n${BLUE} ◎ $(RED)All objects cleaned successfully ${BLUE}◎$(DEF_COLOR)\n"

fclean:
	@${RM} ${OBJS} ${BONUS_OBJECTS}
	@${RM} ${NAME}
	@${RM} bonus
	@echo "\n${BLUE} ◎ $(RED)All objects and executable cleaned successfully${BLUE} ◎$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
