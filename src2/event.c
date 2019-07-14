#include "visu.h"

int		keyboard_controls(t_v *v, int key)
{
	(void)v;
	if (key == SDLK_ESCAPE)
		return (0);
	if (key == SDLK_RIGHT)
		return (1);
	if (key == SDLK_LEFT)
		return (2);
	if (key == SDLK_p)
		return (3);
	// else if (key == SDLK_e)
	// 	open_door(s);
	// else if (key == SDLK_m && HEIGHT / SPACE <= s->height && WIDTH / SPACE
	// 	<= s->width)
	// {
	// 	s->active_map = !s->active_map;
	// 	draw_interface(s);
	// }
	return (-1);
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
}

void	handle_keys(t_v *v, TTF_Font *police)
{
	const Uint8		*keys;

	keys = SDL_GetKeyboardState(NULL);

	ft_draw_grid(v, v->tex);
	ft_draw_case(v);
	update_image(v, v->tex);
	ft_draw_all_ttf(v, police);
	SDL_RenderPresent(v->renderer);
}

void	event_handler(t_v *v)
{
	int			game;
	TTF_Font	*police;

	game = 1;
	police = ft_init_font();
	// SDL_SetRelativeMouseMode(SDL_TRUE);
	ft_draw_menu(v);
	while (game)
	{
		while ((SDL_PollEvent(&(v->event))) != 0)
		{
			if (v->event.type == SDL_QUIT || (v->event.type == SDL_KEYDOWN
				&& keyboard_controls(v, v->event.key.keysym.sym) == 0))
				game = 0;
			if (v->tour < v->last_round && v->event.type == SDL_KEYDOWN
				&& keyboard_controls(v, v->event.key.keysym.sym) == 1)
				v->tour++;
			if (v->tour > 1 && v->event.type == SDL_KEYDOWN
				&& keyboard_controls(v, v->event.key.keysym.sym) == 2)
				v->tour--;
			if (v->event.type == SDL_KEYDOWN
				&& keyboard_controls(v, v->event.key.keysym.sym) == 3)
				v->play = v->play == FALSE ? TRUE : FALSE;
		}
		handle_keys(v, police);
		if (v->play == TRUE && v->tour < v->last_round)
			v->tour++;
		// printf("tour = %d\n", v->tour);
	}
}
