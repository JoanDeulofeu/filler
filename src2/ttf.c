#include "visu.h"

TTF_Font	*ft_init_font(void)
{
	TTF_Font	*font;

	if ((font = TTF_OpenFont("sdl_font/press-start.ttf", 10)) != NULL)
		return (font);
	if ((font = TTF_OpenFont("sdl_font/Open.ttf", 10)) != NULL)
		return (font);
	if ((font = TTF_OpenFont("sdl_font/Roboto.ttf", 10)) != NULL)
		return (font);
	if ((font = TTF_OpenFont("sdl_font/Stylish.ttf", 10)) != NULL)
		return (font);
	ft_error_sdl("SDL_ttf");
	exit(EXIT_FAILURE);
	return (font);
}

void	ft_create_ttf_texture(char *str, int x, int y, t_v *v)
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		pos;
	TTF_Font		*police;

	pos.x = x;
	pos.y = y;
	police = ft_init_font();

	surface = TTF_RenderText_Shaded(police, str,
		(SDL_Color){130, 230, 230, 255}, (SDL_Color){70, 70, 70, 0});

	SDL_SetColorKey(surface, SDL_TRUE, 0);

	texture = SDL_CreateTextureFromSurface(v->renderer, surface);

	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);

	if (surface != NULL)
		SDL_FreeSurface(surface);

	// SDL_SetRenderTarget(v->renderer, tex->texture);
	// SDL_UpdateTexture(tex->texture, NULL, tex->content, WIDTH * sizeof(Uint32));
	// SDL_SetRenderTarget(v->renderer, NULL);
	SDL_RenderCopy(v->renderer, texture, NULL, &pos);
}
