NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
INCLUDES= ./minitalk.h

SRCS_CLIENT = ./utils/ft_printf.c  ./utils/ft_putchar.c \
./utils/ft_putnbr_u.c ./utils/ft_putnbr.c ./utils/ft_putstr.c \
./utils/ft_strlen.c ./utils/ft_atoi.c client.c

SRCS_SERVER = ./utils/ft_printf.c  ./utils/ft_putchar.c \
./utils/ft_putnbr_u.c ./utils/ft_putnbr.c ./utils/ft_putstr.c \
./utils/ft_strlen.c ./utils/ft_atoi.c server.c

SRCS_CLIENT_BONUS = ./utils/ft_printf.c  ./utils/ft_putchar.c \
./utils/ft_putnbr_u.c ./utils/ft_putnbr.c ./utils/ft_putstr.c \
./utils/ft_strlen.c ./utils/ft_atoi.c ./bonus/client_bonus.c

SRCS_SERVER_BONUS = ./utils/ft_printf.c  ./utils/ft_putchar.c \
./utils/ft_putnbr_u.c ./utils/ft_putnbr.c ./utils/ft_putstr.c \
./utils/ft_strlen.c ./utils/ft_atoi.c ./bonus/server_bonus.c

CFLAGS= -Wall -Werror -Wextra -g3 #-fsanitize=address -g3
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_BONUS_CLIENT = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_BONUS_SERVER = $(SRCS_SERVER_BONUS:.c=.o)
GREEN = \033[0;32m

all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT): $(INCLUDES) $(OBJS_CLIENT)
	cc  $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)
	@echo "$(GREEN)Client ready ✅ \e[0m"

$(NAME_SERVER): $(INCLUDES) $(OBJS_SERVER)
	cc  $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)
	@echo "$(GREEN)Server ready ✅ \e[0m"

$(NAME_CLIENT_BONUS): $(INCLUDES) $(OBJS_BONUS_CLIENT)
	cc  $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJS_BONUS_CLIENT)
	@echo "$(GREEN) Client bonus ready ✅ \e[0m"

$(NAME_SERVER_BONUS): $(INCLUDES) $(OBJS_BONUS_SERVER)
	cc  $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJS_BONUS_SERVER)
	@echo "$(GREEN) Server bonus ready ✅ \e[0m"

.c.o:
	cc -Wall -Wextra -Werror -c -o $@ $<

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_BONUS_CLIENT) $(OBJS_BONUS_SERVER)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
