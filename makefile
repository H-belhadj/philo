 CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
SOURCES = circulare_philo.c  error.c  philosophers.c  utils.c  value_arg.c fork.c time.c ft_uslip.c
OBJECTS = $(SOURCES:.c=.o)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "\033[1;32mDONE!\033[0m"

OBJTS: $(SOURCES)
	$(CC) $(CFLAGS) -c $^

clean : 
	@echo "\033[36mCleaning philo....\033[0m"
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all