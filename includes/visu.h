#ifndef VISU_H
# define VISU_H
# include "libft.h"
# include <SDL.h>
# include <SDL_mixer.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <stdio.h>
# define WIDTH 1020
# define HEIGHT 1020

# define FILE_ERROR 1
# define SIZE_ERROR 2
# define SYNTAX_ERROR 3
# define MALLOC_ERROR 4
# define PLAYER_ERROR 5
# define WALL_ERROR 6
# define TRUE 1
# define FALSE 0

typedef struct		s_pos {
	short			x;
	short			y;
}					t_pos;

typedef struct		s_texture {
	Uint32			*content;
	SDL_Texture		*texture;
	Uint32			color_tmp;
}					t_texture;

typedef struct		s_v {
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	t_texture		*tex;
	char			**map;
	int				platx;
	int				platy;
	int				init;
}					t_v;

//SDL.C
void				initialize_sdl(t_v *v);
t_texture			*initialize_texture(t_v *v, int width, int height);
void				update_image(t_v *v, t_texture *tex);
void				set_pixel(t_texture *text, Uint32 color, t_pos coord);

//ERRORS.C
void				display_error(int error_nb);
void				handle_error(int error_nb);
void				ft_error_sdl(char *str);

//EVENT.C
int					keyboard_controls(t_v *v, int key);
void				handle_keys(t_v *v);
void				event_handler(t_v *v);

//MAP.C
void				ft_draw_grid(t_texture *tex);

#endif