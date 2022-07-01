NAME	=	push_swap
SRCS	=	push_swap.c push_swap_utilis.c push_swap_check_first.c push_swap_library_a.c push_swap_library_b.c push_swap_sort_first.c push_swap_sort_second.c push_swap_sort_third.c
CHECKER_OBJS	=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror
CC 		= 	gcc

OBJS	= $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
		make -C ./printf/libft
		mv ./printf/libft/libft.a ./libft.a

		make -C ./printf
		mv ./printf/libftprintf.a ./libftprintf.a

		$(CC) $(CFLAGS) $(SRCS) libft.a libftprintf.a -o $(NAME)

all: $(NAME)

clean:
		rm -rf */*.o push_swap.o push_swap_utilis.o push_swap_check_first.o push_swap_library_a.o push_swap_library_b.o push_swap_sort_first.o push_swap_sort_second.o push_swap_sort_third.o

		rm -rf ${NAME}

fclean: clean
	rm -rf $(NAME).a $(OBJS)
	rm -rf push_swap

		make -C ./printf/libft fclean
		rm -rf */*.o libft.a

		make -C ./printf fclean
		rm -rf */*.o libftprintf.a


re: fclean all

.PHONY: all, clean, fclean, re



