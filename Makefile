# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: johyorti <johyorti@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 17:57:21 by johyorti          #+#    #+#              #
#    Updated: 2025/05/31 02:25:31 by johyorti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I $(LIBFT_DIR)
MAKE_LIB = ar -rcs

# Libft configuration
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(ARCHIVE) $(LIBFT)
	$(CC) $< -L$(LIBFT_DIR) -lft -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

bonus : 
	cd ../checker && make
	
clean :
	rm -f $(OBJS) $(ARCHIVE)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	

re : fclean all

.PHONY : all clean fclea re
