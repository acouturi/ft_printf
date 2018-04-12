# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouturi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:13 by acouturi          #+#    #+#              #
#    Updated: 2018/02/06 19:55:05 by acouturi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = ./libft/

SRC_NAME = ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_putchar.c ft_putendl.c ft_putstr.c ft_strchr.c \
	  ft_strlen.c ft_tolower.c ft_toupper.c ft_strequ.c ft_strnequ.c \
	  ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strdel.c ft_strdel.c \
	  ft_putnbr.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_memalloc.c ft_bzero.c ft_memset.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_memdel.c ft_strnew.c ft_strmap.c ft_strmapi.c ft_strsub.c \
	  ft_strjoin.c ft_strsplit.c ft_strtrim.c ft_lstnew.c ft_lstdelone.c \
	  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_pwd.c \
	  ft_lstaddend.c ft_strrev.c ft_puterror.c ft_isupper.c ft_islower.c \
	  ft_putnstr.c ft_putwchar.c ft_putwstr.c ft_wchartowstr.c ft_strchrc.c \
	  ft_utoabase.c ft_max.c ft_nbrlen.c ft_nbrlenbase.c ft_min.c ft_putnwstr.c\
	  ft_utoabaselen.c ft_chartostr.c

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

PRINT_DIR = ./printf/

PRINT_NAME = ft_printf.c ft_conv.c ft_addsigne.c ft_lirestr.c ft_liretype.c \
			 ft_addnbr.c

SRC += $(addprefix $(PRINT_DIR),$(PRINT_NAME))

# Colors
_GREY	= "\033[0;30m"
_RED	= "\033[0;31m"
_GREEN	= "\033[0;32m"
_YELLOW	= "\033[0;33m"
_BLUE	= "\033[0;34m"
_PURPLE	= "\033[0;35m"
_CYAN	= "\033[0;36m"
_WHITE	= "\033[0;37m"
_NONE	= "\033[0m"

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_PRINT = $(PRINT_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))
OBJ_PRINT = $(addprefix $(OBJ_DIR),$(OBJ_NAME_PRINT))

INCL = -I.

CFLAGS = -Werror -Wall -Wextra
# -ggdb -fsanitize=address -fno-omit-frame-pointer

all : $(NAME)

$(NAME) : $(OBJ) $(OBJ_PRINT)
	@echo $(_GREEN)" [OK]	"$(_PURPLE) "Created :	" $(_NONE) $(NAME)
	@ar rcs $(NAME) $^
	@echo $(_GREEN) "DONE" $(_NONE)

$(OBJ_DIR)%.o : $(PRINT_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo $(_GREEN)" [OK]	"$(_PURPLE) "Compiling :	" $(_NONE) $<
	@gcc $(CFLAGS) -o $@ -c $<

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo $(_GREEN)" [OK]	"$(_YELLOW) "Compiling :	" $(_NONE) $<
	@gcc $(CFLAGS) -o $@ -c $<

clean:
	@echo $(_RED) "Remove :" $(OBJ_DIR)
	@/bin/rm -rf $(OBJ_DIR)
	@echo $(_GREEN) "DONE" $(_NONE)

fclean: clean
	@echo $(_RED) "Remove :" $(NAME)
	@/bin/rm -f $(NAME)
	@echo $(_GREEN) "DONE" $(_NONE)

re: fclean all

bin: all
	@echo $(_GREEN)" [OK]	"$(_BLUE) "Created :	" $(_NONE) "test.exe" 
	@gcc $(CFLAGS) -o test.exe $(NAME) main.c
	@echo $(_GREEN) "DONE" $(_NONE)

exe: all clean

.PHONY: all clean fclean re bin exe
