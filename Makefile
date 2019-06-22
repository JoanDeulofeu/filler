NAME = jgehin.filler
NAME2 = visu

SRC_PATH =		src
SRC_NAME =		mainfiller.c	\
							init.c 				\
							algo.c 				\
							pct.c  				\
							free.c

SRC_PATH2 =		src2
SRC_NAME2 =		mainvisu.c	\
				sdl.c		\
				event.c		\
				errors.c	\
				map.c		\
				case.c

CC = gcc
CFLAGS = -Wall -Wextra #-Werror
LDFLAGS = -L libft/ -lft
LBFLAGS = -I libft/includes/ -MMD

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj
OBJ_NAME2 = $(SRC_NAME2:.c=.o)
OBJ_PATH2 = obj2

HEADER_PATH = includes/
HEADER_NAME = filler.h

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ2 = $(addprefix $(OBJ_PATH2)/,$(OBJ_NAME2))
SRC2 = $(addprefix $(SRC_PATH2)/,$(SRC_NAME2))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

ID = $(shell id -un)

SDLINCL = $(shell $(ABSOLUTE_DIR)/SDL2/bin/sdl2-config --cflags)
SDLFLAGS =  $(SDLINCL) $(shell $(ABSOLUTE_DIR)/SDL2/bin/sdl2-config --libs)

ABSOLUTE_DIR = $(shell pwd)
SDL2_SRC = $(ABSOLUTE_DIR)/SDL2-2.0.9
SDL2_MIX_SRC = $(ABSOLUTE_DIR)/SDL2_mixer-2.0.4

MIXINCL = -I ./SDL2/include/SDL2/
MIXFLAGS = $(MIXINCL) -L./SDL2/lib -lSDL2_MIXER

OK = echo "[32m OK ✓ [0m"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ -o players/$(NAME)
	@$(OK)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(LBFLAGS) -I $(HEADER_PATH) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

#####################################
visu: $(NAME2)

$(NAME2): $(OBJ2)
	@make -C libft/
	@$(CC) $(CFLAGS) $(LDFLAGS) $(SDLFLAGS) $(MIXFLAGS) $(MIXINCL) $(LDLIBS) $(SDLFMK) $^ -o $@
	@$(OK)

$(OBJ_PATH2)/%.o: $(SRC_PATH2)/%.c | $(OBJ_PATH2)
	@$(CC) $(CFLAGS) $(LBFLAGS) -I $(HEADER_PATH) $(SDLINCL) $(MIXINCL) -o $@ -c $<

$(OBJ_PATH2):
	@mkdir $(OBJ_PATH2) 2> /dev/null || true

##################################

sdl :
	if test ! -f SDL_2.0.9.tar.gz; \
	then curl http://libsdl.org/release/SDL2-2.0.9.tar.gz -o SDL_2.0.9.tar.gz; \
	fi
	if test ! -d SDL2-2.0.9; \
	then tar xvf SDL_2.0.9.tar.gz; \
	fi
	mkdir -p SDL2 2> /dev/null || true
	mkdir -p SDL2/build 2> /dev/null || true
	cd SDL2/build; \
		$(SDL2_SRC)/configure --prefix $(ABSOLUTE_DIR)/SDL2; \
		@make -j6; \
		make install;
	cd $(ABSOLUTE_DIR)
	if test ! -f SDL2_mixer-2.0.4.tar.gz; \
	then curl https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.4.tar.gz -o SDL2_mixer-2.0.4.tar.gz; \
	fi
	if test ! -d SDL2_mixer-2.0.4; \
	then tar xvf SDL2_mixer-2.0.4.tar.gz; \
	fi
	cd SDL2/build; \
		$(SDL2_MIX_SRC)/configure --prefix $(ABSOLUTE_DIR)/SDL2; \
		@make -j6; \
		make install;

sdlclean:
	@rm -rf $(SDL2_SRC) $(SDL2_MIX_SRC) SDL_2.0.9.tar.gz SDL2_mixer-2.0.4.tar.gz SDL2
	@$(OK)

visuclean:
	@make clean -C libft/
	@rm -f $(OBJ2) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH2) 2> /dev/null || true
	@rm -f $(NAME2)
	@$(OK)

clean:
	@make clean -C libft/
	@rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C libft/
	@rm -f players/$(NAME)
	@$(OK)

re: fclean
	$(MAKE) all

.PHONY: make clean fclean re sdl sdlclean

-include $(OBJ:.o=.d)
