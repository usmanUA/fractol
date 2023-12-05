flags = -Wall -Wextra -Werror
LIBFT = libft.a
NAME = fractol
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FILES = ft_math_utils.c \
		ft_fractol.c \
		ft_fractset.c \
		ft_string_utils.c \
		ft_rendering.c \
		ft_events.c \
		ft_mlx_win.c \
		

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@[ -f $(NAME) ] || (echo "$(GREEN)Creating The Executable:   $(NAME)$(RESET)" && cc -g $(OBJS) libft/$(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME))
	
%.o: %.c
	@[ -f $@ ] || (echo "$(GREEN)Creating Object File: $@$(RESET)" && cc $(flags) -Imlx -c $< -o $@)
	
$(LIBFT):
	@$(MAKE) -C libft

clean:
	@echo "$(RED)Cleaning Object Files for libft, ft_printf and fractol$(RESET)"
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)Removing   $(LIBFT) and $(NAME)$(RESET)"
	@rm -rf libft/$(LIBFT)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
