NAME = cub3d

HEADER = includes/cub3d.h 

CFLAGS = -g -Wall -Werror -Wextra

CC = gcc 

LIBFT = libraries/libft/libft.a

OBJS_DIR = objs
SRC_DIR = src

INC := -I $(INCLUDE_DIR)

SRCS = main.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(LIBFT) $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -I -c -o $@ $<

$(LIBFT):
	$(MAKE) -C libraries/libft

$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(CFLAGS) $(INC) -I $^ -o $(NAME)
	@echo "\033[92mFiles made 🤔\033[0m"

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C libraries/libft
	@echo "\033[1;34mA\033[1;31ml\033[1;32ml \033[1;33mc\033[1;30ml\033[1;35me\033[1;36ma\033[1;37mn\033[0m"

fclean:
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@make fclean -C libraries/libft
	@echo "\033[0;31mFiles killed💀❌\033[0m"

re:	fclean all

.PHONY: all clean fclean re