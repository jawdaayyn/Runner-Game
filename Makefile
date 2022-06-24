NAME	=	PEWPEW

SRC		= 	source/main.c\
			source/draw.c\
			source/init.c\
			source/input.c\


OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	+= 	-I./include
CFLAGS 	+= 	-W -Werror -Wextra -Wall

LIBS 	+= 	-lSDL2 -lSDL2_image -lSDL2_ttf

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	$(RM) 	$(OBJ)
 
fclean:		clean
	$(RM) $(NAME)
