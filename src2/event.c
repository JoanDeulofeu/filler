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

void	handle_keys(t_v *v)
{
	const Uint8 *keys;

	keys = SDL_GetKeyboardState(NULL);
	// if (keys[LEFT] || keys[RIGHT] || keys[UP] || keys[DOWN])
	// 	move_player(s, keys, keys[SPRINT]);
	// if (keys[LEFT_AR] || keys[RIGHT_AR] || keys[UP_AR] || keys[DOWN_AR])
	// 	turn_camera(s, keys, 0);
	// if (s->sdl->event.type == SDL_MOUSEMOTION)
	// 	turn_camera(s, keys, 1);
	// if (s->active_map && HEIGHT / SPACE <= s->height && WIDTH / SPACE
	// 	<= s->width)
	// 	draw_minimap(s, 0, 0);
	// else
	// {
	// 	raycast_visualization(s);
		// draw_player(s, s->p_pos);
		// update_image(s, s->sdl->game);
		ft_draw_grid(v, v->tex);
		ft_draw_case(v);
		update_image(v, v->tex);
		ft_create_ttf_texture("SCORE JOUEUR 1 : ", 1070, 200, v);
		SDL_RenderPresent(v->renderer);

	// }
}

void	event_handler(t_v *v)
{
	int		game;

	game = 1;
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
		handle_keys(v);
		if (v->play == TRUE && v->tour < v->last_round)
			v->tour++;
		// printf("tour = %d\n", v->tour);
	}
}
