# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliandie <aliandie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/26 13:38:59 by aliandie          #+#    #+#              #
#    Updated: 2015/04/17 16:36:05 by aliandie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
CCLIB = -Llibft -lft
CCFLAGS = -Wall -Werror -Wextra -g
SRCDIR = src
OBJDIR = obj
INCDIR = includes libft/includes

# SRC += 	main.c
# SRC	+=	env_init.c
 SRC +=	arg_init.c
# SRC +=	ft_cd.c
# SRC +=	find_arg_p.c
SRC += parser.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
		@make -C libft
		@gcc $(CCLIB) -o $(NAME) $(OBJS)
build:
		@mkdir -p $(OBJDIR)
clean:
		@make -C libft clean
		@rm -f $(OBJS)
fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)
re: fclean all

dev : all
		@./$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		@gcc -c $(CCFLAGS) $(INCS) -o $@ $<
