#include "visu.h"

void	set_pixel(t_texture *text, Uint32 color, t_pos coord)
{
	if (coord.x >= 0 && coord.x < WIDTH && coord.y >= 0 && coord.y < HEIGHT)
	{
		text->content[coord.x + coord.y * WIDTH] = color;
	}
}

void	update_image(t_v *v, t_texture *tex)
{
	SDL_SetRenderTarget(v->renderer, tex->texture);
	SDL_UpdateTexture(tex->texture, NULL, tex->content, WIDTH * sizeof(Uint32));
	SDL_SetRenderTarget(v->renderer, NULL);
	SDL_RenderCopy(v->renderer, tex->texture, NULL, NULL);
	SDL_RenderPresent(v->renderer);
}

t_texture	*initialize_texture(t_v *v, int width, int height)
{
	t_texture	*text;

	if (!(text = (t_texture *)malloc(sizeof(t_texture))))
		return (NULL);
	if (!(text->content = (Uint32 *)malloc(width * height * sizeof(Uint32))))
		return (NULL);
	if (!(text->texture = SDL_CreateTexture(v->renderer,
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height)))
		return (NULL);
	text->color_tmp = 0xFFFFFFFF;
	return (text);
	//cibabdcea1425
}

TTF_Font	*ft_init_font(void)
{
	TTF_Font	*font;

	if ((font = TTF_OpenFont("sdl_font/press-start.ttf", 20)) != NULL)
		return (font);
	ft_error_sdl("SDL_ttf");
	exit(EXIT_FAILURE);
	return (font);
}

void		initialize_sdl(t_v *v)
{
	v->window = NULL;
	v->renderer = NULL;
	// v->font = NULL;
	v->tex = NULL;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		ft_error_sdl("Échec de l'initialisation de la SDL");
	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur initialisation TTF_Init: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	if (!(v->window = SDL_CreateWindow("Filler", 200,
		200, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		ft_error_sdl("Échec de creation de la fenetre");
	if (!(v->renderer = SDL_CreateRenderer(v->window, -1, 0)))
		ft_error_sdl("Échec de chargement du renderer");
	if (!(v->tex = initialize_texture(v, WIDTH, HEIGHT)))
		exit(-1);
	// v->font = init_font();
}
