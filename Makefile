# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msukhare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 15:46:51 by msukhare          #+#    #+#              #
#    Updated: 2018/04/20 08:35:49 by msukhare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs/

OBJ_PATH = obj/

CPPFLAGS = -I includes/ -I libft/include/

CC = gcc

MK = make -C

SRCLFT = libft/

LFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

#-----------------------------SRC---------------------------------------------#

SRC_NAME = manage_list.c\
	   ft_swap_in_pile.c\
	   ft_rev_rot.c\
	   ft_creatlink.c\
	   ft_push.c\
	   creat_pile.c\
	   check.c\
	   ft_rotate.c

OBJ_SRC_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_SRC_NAME))

#-----------------------------CHECKER-----------------------------------------#

NAME_CHECKER = checker

SRC_CHECK = checker.c\
	      ft_exec_cmd.c

OBJ_CHECKER_NAME = $(SRC_CHECK:.c=.o)

SRC_CHECKER = $(addprefix $(SRC_PATH),$(SRC_CHECK))

OBJ_CHECKER = $(addprefix $(OBJ_PATH),$(OBJ_CHECKER_NAME))

#-----------------------------PUSH_SWAP---------------------------------------#

NAME_PUSH_SWAP = push_swap

SRC_PUSH_SWAP = push_swap.c\
		ft_tri_quick.c\
		ft_sort_tree.c\
		ft_push_sup_in_a.c\
		ft_insertion_sort.c\
		ft_push_inf_in_b.c\
		ft_sort_six.c

OBJ_PUSH_NAME = $(SRC_PUSH_SWAP:.c=.o)

SRC_PUSH = $(addprefix $(SRC_PATH),$(SRC_PUSH_SWAP))

OBJ_PUSH = $(addprefix $(OBJ_PATH),$(OBJ_PUSH_NAME))

#--------------------------------COMPILE--------------------------------------#

all : $(LFT) $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(LFT):
	$(MK) $(SRCLFT)

$(NAME_CHECKER): $(OBJ_CHECKER) $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME_CHECKER) $(OBJ_CHECKER) $(OBJ) $(LFT)

$(NAME_PUSH_SWAP): $(OBJ_PUSH) $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME_PUSH_SWAP) $(OBJ_PUSH) $(OBJ) $(LFT)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	make clean -C $(SRCLFT)
	@rm -vf $(OBJ) $(OBJ_CHECKER) $(OBJ_PUSH)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C $(SRCLFT)
	rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)

re:fclean all

.PHONY: all, clean, fclean, re
