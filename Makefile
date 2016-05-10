ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME				= libft_malloc_${HOSTTYPE}.so
LINKED_NAME	= libft_malloc.so

CC					= clang
FLAG				= -shared -Wall -Werror -Wextra -pedantic
INCS				= -I inc -I libft/inc
LIBS				= -L libft -lft

SRC					= $(DIR_SRC)/malloc.c \
							$(DIR_SRC)/realloc.c \
							$(DIR_SRC)/free.c \

DIR_SRC			= src

all: libft $(NAME) symlink

libft:
	@$(MAKE) -C libft

symlink:
	@if [ ! -e ${LINKED_NAME} ]; then \
		/bin/ln -s ${NAME} ${LINKED_NAME}; \
		printf "\e[32m[Symlink created]\e[0m\n"; \
	fi

$(NAME): $(SRC)
	@printf "\e[32m------------------------------------------------------\e[0m\n"
	@$(CC) $(FLAG) $(SRC) $(LIBS) -o $(NAME)
	@printf "\e[34m%-51s\e[0m" "$@"
	@printf "\e[32m[✔]\e[0m\n"
	@printf "\e[32m------------------------------------------------------\e[0m\n"

clean:
	@$(MAKE) -C libft $@
	@printf "\e[32m[✔]\e[0m Project cleaned.\n"

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -f $(NAME) $(LINKED_NAME);
	@printf "\e[32m[✔]\e[0m Project fcleaned.\n"

re: fclean all

.PHONY: clean fclean re libft
