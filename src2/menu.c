#include "visu.h"

int		ft_case_title(t_v *v, int x, int y, int sz)
{
	int		svx;
	int		svy;
	Uint32	color;
	t_pos	coord;

	svx = x;
	svy = y;
	color = 0x48cfcfFF;//     #48cfcf
	while (y < svy + sz)
	{
		while (x < svx + sz)
		{
			coord.x = x;
			coord.y = y;
			set_pixel(v->tex, color, coord);
			x++;
		}
		y++;
		x = svx;
	}
	return (0);
}

int		ft_draw_title(t_v *v, int startx, int starty)
{
	int sz = 14;

	startx += 18;
	starty += 15;
	//F
	ft_case_title(v, startx + (sz * 1), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 2), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 3), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 1), starty + (sz * 2), sz);
	ft_case_title(v, startx + (sz * 1), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 2), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 1), starty + (sz * 4), sz);
	ft_case_title(v, startx + (sz * 1), starty + (sz * 5), sz);
	//I
	ft_case_title(v, startx + (sz * 5), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 5), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 5), starty + (sz * 4), sz);
	ft_case_title(v, startx + (sz * 5), starty + (sz * 5), sz);
	//L
	ft_case_title(v, startx + (sz * 7), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 7), starty + (sz * 2), sz);
	ft_case_title(v, startx + (sz * 7), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 7), starty + (sz * 4), sz);
	ft_case_title(v, startx + (sz * 7), starty + (sz * 5), sz);
	ft_case_title(v, startx + (sz * 8), starty + (sz * 5), sz);
	ft_case_title(v, startx + (sz * 9), starty + (sz * 5), sz);
	//L
	ft_case_title(v, startx + (sz * 11), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 11), starty + (sz * 2), sz);
	ft_case_title(v, startx + (sz * 11), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 11), starty + (sz * 4), sz);
	ft_case_title(v, startx + (sz * 11), starty + (sz * 5), sz);
	ft_case_title(v, startx + (sz * 12), starty + (sz * 5), sz);
	ft_case_title(v, startx + (sz * 13), starty + (sz * 5), sz);
	//E
	ft_case_title(v, startx + (sz * 15), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 16), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 17), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 15), starty + (sz * 2), sz);
	ft_case_title(v, startx + (sz * 15), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 16), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 15), starty + (sz * 4), sz);
	ft_case_title(v, startx + (sz * 15), starty + (sz * 5), sz);
	ft_case_title(v, startx + (sz * 16), starty + (sz * 5), sz);
	ft_case_title(v, startx + (sz * 17), starty + (sz * 5), sz);
	//R
	ft_case_title(v, startx + (sz * 19), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 20), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 21), starty + (sz * 1), sz);
	ft_case_title(v, startx + (sz * 19), starty + (sz * 2), sz);
	ft_case_title(v, startx + (sz * 21), starty + (sz * 2), sz);
	ft_case_title(v, startx + (sz * 19), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 20), starty + (sz * 3), sz);
	ft_case_title(v, startx + (sz * 19), starty + (sz * 4), sz);
	ft_case_title(v, startx + (sz * 21), starty + (sz * 4), sz);
	ft_case_title(v, startx + (sz * 19), starty + (sz * 5), sz);
	ft_case_title(v, startx + (sz * 21), starty + (sz * 5), sz);
	return (0);
}

// SDL_Texture	*ft_write_menu(t_v *v)
// {
// 	SDL_Surface *texte = NULL;
// 	SDL_Texture *texture;
// 	SDL_Rect position;
// 	TTF_Font *police = NULL;
// 	SDL_Color color;
// 	Uint32 rmask, gmask, bmask, amask;
//
// 	color.r = 255;
// 	color.g = 50;
// 	color.b = 50;
// 	color.a = 255;
//
// 	// /* Chargement de la police */
// 	// police = TTF_OpenFont("angelina.ttf", 65);
// 	// /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
// 	// texte = TTF_RenderText_Blended(police, "Welcome to 42!", color);
// 	// position.x = 60;
// 	// position.y = 370;
// 	// if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
// 	// {
// 	// 	rmask = 0xff000000;
// 	// 	gmask = 0x00ff0000;
// 	// 	bmask = 0x0000ff00;
// 	// 	amask = 0x000000ff;
// 	// }
// 	// else
// 	// {
// 	// 	rmask = 0x000000ff;
// 	// 	gmask = 0x0000ff00;
// 	// 	bmask = 0x00ff0000;
// 	// 	amask = 0xff000000;
// 	// }
// 	// texture = SDL_CreateTextureFromSurface(v->renderer, texte);
// 	// if (texture == NULL) {
// 	//     fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
// 	//     exit(1);
// 	// }
// 	// SDL_FreeSurface(texte);
// 	// texte = NULL;
// 	return (texture);
// }


// void	component_text(const char *str, int x, int y, t_v *v)
// {
// 	SDL_Surface		*surface;
// 	SDL_Texture		*texture;
// 	SDL_Rect		pos;
//
// 	pos.x = x;
// 	pos.y = y;
//
// 	surface = TTF_RenderText_Shaded(sdl->font, "Welcome to 42!",
// 		(SDL_Color){255, 255, 255, 255}, (SDL_Color){70, 70, 70, 0});
//
// 	SDL_SetColorKey(surface, SDL_TRUE, 0);
//
// 	texture = SDL_CreateTextureFromSurface(v->renderer, surface);
//
// 	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
//
// 	if (surface != NULL)
// 		SDL_FreeSurface(surface);
//
// 	SDL_SetRenderTarget(v->renderer, tex->texture);
// 	SDL_UpdateTexture(tex->texture, NULL, tex->content, WIDTH * sizeof(Uint32));
// 	SDL_SetRenderTarget(v->renderer, NULL);
// 	return (text);
// }

int		ft_draw_menu(t_v *v)
{
	Uint32	color;
	t_pos	coord;
	// SDL_Texture *txt;

	coord.x = HEIGHT + 20;
	coord.y = 20;
	while (coord.y < HEIGHT - 20)
	{
		while (coord.x < WIDTH - 20)
		{
			if (coord.x == HEIGHT + 20 || coord.x == WIDTH - 21
				|| coord.y == 20 || coord.y == HEIGHT - 21)
				color = 0x88d5d5FF;
			else
				color = 0x282828FF;
			set_pixel(v->tex, color, coord);
			coord.x++;
		}
		coord.x = HEIGHT + 20;
		coord.y++;
	}
	ft_draw_title(v, HEIGHT + 20, 20);
	// txt = ft_write_menu(v);
	return (0);
}
