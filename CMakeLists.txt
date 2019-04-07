cmake_minimum_required(VERSION 3.13)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall -Werror -Wextra")
file(GLOB LIBFT ft_printf/*.c ft_printf/*.h ft_printf/libft/*.c ft_printf/libft/*.h)
set(SOURCES  check_arg.c
        diff_num.c
        push_swap.c
        func_t_swap.c
        func_t_stack.c
        print_swap.c
        operations.c
        check_number_space.c
        command.c
        command_1.c
        command_2.c
        validation_check.c
        solve.c
        position.c)

add_executable(push_swap ${SOURCES} ${LIBFT})




