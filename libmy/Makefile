##
## Makefile for libmy in Makefile
## 
## Made by Maxime Louet
## Login   <maxime.louet@epitech.eu>
## 
## Started on  Thu Nov 17 13:02:54 2016 Maxime Louet
## Last update Thu Mar 29 15:35:23 2017 Maxime Louet
##

MAKEFLAGS	+= --no-print-directory -s -k

CC	= gcc

CFLAGS	+= -Wall -Wextra -ansi -pedantic
CFLAGS	+= -Wmissing-prototypes -Wfloat-equal -Wstrict-prototypes -Wshadow
CFLAGS	+= -Winit-self -Wcast-align -Waggregate-return -Wunreachable-code
CFLAGS	+= -Wlogical-op -Wdisabled-optimization -Wunused-result
CFLAGS  += -fstrict-overflow -Wstrict-overflow=4
CFLAGS	+= -fstack-protector-strong -Wstack-protector

CPPFLAGS	+= -I.

AR	= ar

ARFLAGS	= rc

NAME	= libmy.a

SRC	= my_atoi.c \
	  my_basename.c \
	  my_calloc.c \
	  my_concat.c \
	  my_extcmp.c \
	  my_free_wt.c \
	  my_gnl.c \
	  my_isalnum.c \
	  my_isalpha.c \
	  my_isdigit.c \
	  my_isspace.c \
	  my_itoa.c \
	  my_memset.c \
	  my_nbrlen.c \
	  my_print_wt.c \
	  my_putchar.c \
	  my_putchar_fd.c \
	  my_putnbr_base.c \
	  my_putnbr_base_fd.c \
	  my_putnbr.c \
	  my_putnbr_fd.c \
	  my_putnstr.c \
	  my_putnstr_fd.c \
	  my_putstr.c \
	  my_putstr_fd.c \
	  my_revstr.c \
	  my_strcat.c \
	  my_strchr.c \
	  my_strcmp.c \
	  my_strcpy.c \
	  my_strdup.c \
	  my_str_isalnum.c \
	  my_str_isdigit.c \
	  my_strlen.c \
	  my_strncmp.c \
	  my_strncpy.c \
	  my_strndup.c \
	  my_strnlen.c \
	  my_str_to_wt.c \
	  my_tolower.c \
	  my_toupper.c \
	  my_wtdup.c \
	  my_wtlen.c \
	  my_dprintf.c \
	  my_printf.c \
	  my_vdprintf.c \
	  pf_character.c \
	  pf_decint.c \
	  pf_percent.c \
	  pf_pointer.c \
	  pf_string.c

OBJ	= $(SRC:.c=.o)

RM	= rm -f


all: info $(NAME)

info:
	-@echo -ne "Building libmy...\n"

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	-@echo -ne "Finished building libmy.\n"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
