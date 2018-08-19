NAME = libft.a

SRC	=			ft_lst/ft_lstadd.c \
                ft_lst/ft_lstadd_beginning.c \
                ft_lst/ft_lstadd_end.c \
                ft_lst/ft_lstconcat.c \
                ft_lst/ft_lstdel.c \
                ft_lst/ft_lstdel.c \
                ft_lst/ft_lstdelone.c \
                ft_lst/ft_lstinsert_after.c \
                ft_lst/ft_lstinsert_before.c \
                ft_lst/ft_lstiter.c \
                ft_lst/ft_lstmap.c \
                ft_lst/ft_lstnew.c \
				ft_mem/ft_memalloc.c \
                ft_mem/ft_memccpy.c \
                ft_mem/ft_memchr.c \
                ft_mem//ft_memcmp.c \
                ft_mem/ft_memcpy.c \
                ft_mem/ft_memdel.c \
                ft_mem/ft_memmove.c \
                ft_mem/ft_memset.c \
				ft_nbr/ft_atoi.c \
                ft_nbr/ft_atoi_base.c \
                ft_nbr/ft_atol.c \
                ft_nbr/ft_atoll.c \
				ft_nbr/ft_ltoa.c \
                ft_nbr/ft_itoa.c \
                ft_nbr/ft_itoa_base.c \
                ft_nbr/ft_nbrlen.c \
                ft_nbr/ft_power.c \
                ft_nbr/ft_power_long.c \
				ft_nbr/ft_sqrt.c \
				ft_nbr/ull_len.c \
				ft_nbr/ull_toa.c \
				ft_put/ft_pputstr.c \
				ft_put/ft_pputnbr.c \
				ft_put/ft_putchar.c \
				ft_put/ft_putchar_fd.c \
               	ft_put/ft_putcolor.c \
                ft_put/ft_putendl.c \
				ft_put/ft_pputendl.c \
                ft_put/ft_putendl_fd.c \
                ft_put/ft_putnbr.c \
              	ft_put/ft_putnbr_fd.c \
                ft_put/ft_putnstr.c \
               	ft_put/ft_putrainbow.c \
                ft_put/ft_putstr.c \
                ft_put/ft_putstr_array.c \
                ft_put/ft_putstr_fd.c \
				utils/ft_bzero.c \
				utils/ft_intsize.c \
                utils/ft_isalnum.c \
                utils/ft_isalpha.c \
                utils/ft_isascii.c \
                utils/ft_isdigit.c \
                utils/ft_isprint.c \
               	utils/ft_tolower.c \
               	utils/ft_toupper.c \
                utils/get_next_line.c \
				ft_str/ft_str_realloc.c \
                ft_str/ft_str_replace.c \
                ft_str/ft_strcat.c \
                ft_str/ft_strchr.c \
				ft_str/ft_strclr.c \
				ft_str/ft_strcmp.c \
                ft_str/ft_strcount.c \
                ft_str/ft_strcpy.c \
                ft_str/ft_strdel.c \
                ft_str/ft_strdel_array.c \
                ft_str/ft_strdup.c \
               	ft_str/ft_strequ.c \
                ft_str/ft_striter.c \
				ft_str/ft_striteri.c \
                ft_str/ft_strjoin.c \
                ft_str/ft_strjoin_array.c \
                ft_str/ft_strjoinreplace.c \
                ft_str/ft_strlcat.c \
                ft_str/ft_strlen.c \
                ft_str/ft_strlen_char.c \
                ft_str/ft_strmap.c \
                ft_str/ft_strmapi.c \
               	ft_str/ft_strncat.c \
                ft_str/ft_strncmp.c \
                ft_str/ft_strncpy.c \
               	ft_str/ft_strndup.c \
                ft_str/ft_strnequ.c \
                ft_str/ft_strnew.c \
				ft_str/ft_strnew_set.c \
                ft_str/ft_strnstr.c \
                ft_str/ft_strrchr.c \
                ft_str/ft_strrev.c \
                ft_str/ft_strsplit.c \
                ft_str/ft_strstr.c \
				ft_str/ft_strsub.c \
				ft_str/ft_strjoin3.c \
				ft_str/ft_strtrim.c \
				ft_str/ft_sstrdel.c \
				ft_str/ft_sstrdup.c \
				ft_str/ft_sstrlen.c \
				ft_str/ft_strcchr_rev.c \
				ft_str/ft_sstrnew.c \
				ft_str/ft_sstrtostr.c \
				ft_str/ft_strxcchr.c \
				ft_str/ft_strcchr.c \
				ft_str/ft_sstradd.c  

OBJ		= $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I.
AR		= ar
ARFLAGS	= rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "LIBFT COMPILED ✓"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Building: $@"

clean:
	@rm -f $(OBJ)
	@echo "libft objects deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "libft.a deleted"

re: fclean all
