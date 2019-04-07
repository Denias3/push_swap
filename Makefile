NAME = push_swap
NAME2 = checker

SRC = push_swap.c\
check_arg.c\
diff_num.c\
func_t_swap.c\
func_t_stack.c\
print_swap.c\
operations.c\
check_number_space.c\
command.c\
command_1.c\
command_2.c\
validation_check.c\
solve.c\
position.c

SRC2 = checker.c\
check_arg.c\
diff_num.c\
func_t_swap.c\
func_t_stack.c\
print_swap.c\
operations.c\
check_number_space.c\
command.c\
command_1.c\
command_2.c\
validation_check.c\

INCLUDES = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(SRC)
		@make -C ft_printf
		@gcc -Wall -Werror -Wextra $(SRC) $(INCLUDES) -o $(NAME)
		@gcc -Wall -Werror -Wextra $(SRC2) $(INCLUDES) -o $(NAME2)
		@echo "-> compil push_swap and checker"

comp:
		@gcc -Wall -Werror -Wextra $(SRC) $(INCLUDES) -o $(NAME)
		@gcc -Wall -Werror -Wextra $(SRC2) $(INCLUDES) -o $(NAME2)
		@echo "-> comp push_swap and checker"

clean:
		@make clean -C ft_printf
		@echo "-> clean push_swap"
fclean: clean
		@make fclean -C ft_printf
		@rm -f $(NAME)
		@rm -f $(NAME2)
		@echo "-> fclean push_swap"

re: fclean all
		@echo "-> re push_swap"