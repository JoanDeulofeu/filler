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


void	ft_draw_all_ttf(t_v *v, TTF_Font *police)
{
	t_ttf		ttf;

	ttf.r = 130;
	ttf.g = 230;
	ttf.b = 230;
	ttf.pos.x = 1070;
	ttf.pos.y = 200;
	ttf.str = ft_strdup("SCORE JOUEUR 1 : ");
	ft_create_ttf(ttf, v, police);
	ttf.pos.x = 1270;
	ttf.pos.y = 200;
	ttf.str = ft_strdup(ft_itoa(v->j1score));
	ft_create_ttf(ttf, v, police);


	ttf.r = 175;
	ttf.g = 70;
	ttf.b = 215;
	ttf.pos.x = 1070;
	ttf.pos.y = 400;
	ttf.str = ft_strdup("SCORE JOUEUR 2 : ");
	ft_create_ttf(ttf, v, police);
	ttf.pos.x = 1270;
	ttf.pos.y = 400;
	ttf.str = ft_strdup(ft_itoa(v->j2score));
	ft_create_ttf(ttf, v, police);

	if (v->tour == v->last_round)
	{
		ttf.r = 30;
		ttf.g = 255;
		ttf.b = 30;
		ttf.pos.x = 1140;
		ttf.pos.y = 800;
		ttf.str = ft_strdup("JOUEUR 1 GAGNE !");
		ft_create_ttf(ttf, v, police);
	}
}
