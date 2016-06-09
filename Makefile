ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME			= libft_malloc_${HOSTTYPE}.so
LINKED_NAME		= libft_malloc.so

CC				= clang
FLAG			= -shared
#FLAG			= -shared -Wall -Werror -Wextra -pedantic
INCS			= -I inc -I libft/inc
LIBS			= -L libft -lft

SRC				= $(DIR_SRC)/malloc.c \
				$(DIR_SRC)/realloc.c \
				$(DIR_SRC)/free.c \
				$(DIR_SRC)/create_zone.c \
				$(DIR_SRC)/request_zone_and_last.c \
				$(DIR_SRC)/show_alloc_mem.c \
				$(DIR_SRC)/request_space.c \
				$(DIR_SRC)/find_free_block.c \
				$(DIR_SRC)/ft_idiot_putnbr.c \
				$(DIR_SRC)/get_base.c \

DIR_SRC			= src

all: libft $(NAME) symlink

libft:
	@make -C libft

norme:
	@norminette src/*.c inc/*.h

test: all
	@$(CC) $(INCS) -o test/unit test/main.c -L. -lft_malloc
	@./test/unit

symlink:
	@if [ ! -e ${LINKED_NAME} ]; then \
		/bin/ln -s ${NAME} ${LINKED_NAME}; \
		printf "\e[32m[Symlink created]\e[0m\n"; \
	fi

$(NAME): $(SRC)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(INCS) $(FLAG) $(SRC) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

clean:
	@make -C libft $@
	@/bin/rm -rf .obj;
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@make -C libft $@
	@/bin/rm -f $(NAME) $(LINKED_NAME);
	@/bin/rm -f test/unit;
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

.PHONY: clean fclean re libft
