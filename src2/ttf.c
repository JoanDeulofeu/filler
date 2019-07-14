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

void	ft_create_ttf(t_ttf ttf, t_v *v, TTF_Font *police)
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	surface = TTF_RenderText_Shaded(police, ttf.str,
		(SDL_Color){ttf.r, ttf.g, ttf.b, 255}, (SDL_Color){70, 70, 70, 0});

	SDL_SetColorKey(surface, SDL_TRUE, 0);

	texture = SDL_CreateTextureFromSurface(v->renderer, surface);

	SDL_QueryTexture(texture, NULL, NULL, &ttf.pos.w, &ttf.pos.h);

	if (surface != NULL)
		SDL_FreeSurface(surface);

	// SDL_SetRenderTarget(v->renderer, tex->texture);
	// SDL_UpdateTexture(tex->texture, NULL, tex->content, WIDTH * sizeof(Uint32));
	// SDL_SetRenderTarget(v->renderer, NULL);
	SDL_RenderCopy(v->renderer, texture, NULL, &ttf.pos);
}
