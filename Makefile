NAME := libftprintf.a

HFILE := $(SRC_DIR)ft_printf.h

CFILES :=	ft_printf.c \
			char_printers.c \
			nbr_printers.c \
			hex_printers.c \

SRC_DIR := sources/
OBJ_DIR := objects/
LIBFT_DIR := LIBFT/

SRCS := $(addprefix $(SRC_DIR), $(CFILES))

OFILES := $(CFILES:.c=.o)
OBJS := $(addprefix $(OBJ_DIR), $(OFILES))
CFLAGS ?= -Wall -Wextra -Werror

LIBFT := LIBFT/libft.a

$(NAME): GREETING $(OBJ_DIR) $(OBJS) $(LIBFT)
	@printf "$(WHITE) BUILDING LIBRARY \n$(YELLOW) $(NAME) $(GREEN) (DONE)\n$(GREEN)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
	@cp $(LIBFT) $(NAME)
	@ar -cr $(NAME) $(OBJS)
	$(END_MSG)

$(LIBFT):
	@printf "$(PURPLE)━━━━building LIBFT uwu━━━━\n"
	@$(MAKE) all -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $(CFLAGS) $< -o $@ -I$(LIBFT_DIR) -I$(SRC_DIR)
	@printf "$@  $(GREEN) (DONE) $(BLUE)\n"

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

test: $(NAME)
	@$(CC) $(NAME) testing.c -LLIBFT -lft -L. -lftprintf -I$(SRC_DIR) -ILIBFT/ -o cute_little_test
	@printf "$(PURPLE)\n:*✧･ﾟ cute_little_test :*✧･ﾟ $(WHITE)has been made :) \n\n\n"


clean:
	$(RM_MSG)
	@$(RM) -rf $(OBJ_DIR)

fclean: clean
	@$(RM)	$(NAME)

re: fclean $(NAME)

GREETING:
	$(START_MSG)

.PHONY: clean fclean re test


PINK = \x1b[35;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
GREEN = \x1b[32;01m
YELLOW = \x1b[33;01m
WHITE = \x1b[31;37m
COLORRESET = \x1b[0m
PURPLE =  \033[1;35m
END_MSG = @printf "$(PINK)\n\n✧･:*✧･ﾟ:*💖 all done cutie 💖* :･ﾟ✧*:･ﾟ✧\n"
START_MSG = @printf "$(GREEN)⭒☆━━━━━━━━━━ MAKEFILE START ━━━━━━━━⭒☆\n$(WHITE) COMPILING FILES\n$(BLUE)"
RM_MSG = @printf "$(RED)\n━━━━━━━━━━━━━━━━━━━━ \n|objects cleaned :)|\n━━━━━━━━━━━━━━━━━━━━\n "