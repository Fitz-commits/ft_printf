LIBFT_ROOT = ./libft

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
INCFLAGS = -I$(LIBFT_ROOT)

RM = rm -f
LIB = ar rcs
MAKE = make

NAME = libftprintf.a
SRC = ft_printf.c checks.c conv.c ft_putstr_fdi.c toa1.c toa2.c printing.c flags_handling.c ft_itoa.c
OBJ = $(SRC:.c=.o)
	INCLUDE = ft_printf.h

all: libft_all $(NAME)

$(NAME): $(OBJ)
		cp $(LIBFT_ROOT)/libft.a $(NAME)
			$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
		$(CC) $(CCFLAGS) $(INCFLAGS) -c -o $@ $<

bonus: all

clean: libft_clean
		$(RM) $(OBJ)

fclean: libft_fclean clean
		$(RM) $(NAME)

re: fclean all

libft_all:
		$(MAKE) -C $(LIBFT_ROOT) all

libft_bonus:
		$(MAKE) -C $(LIBFT_ROOT) bonus

libft_clean:
		$(MAKE) -C $(LIBFT_ROOT) clean

libft_fclean:
		$(MAKE) -C $(LIBFT_ROOT) fclean
