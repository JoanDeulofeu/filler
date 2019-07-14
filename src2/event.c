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

void	ft_draw_piece_bar(t_v *v, t_pos pos, Uint32 color)
{
	int		x = 0;
	int		y = 0;
	t_pos	coord;

	while (y < 25)
	{
		while (x < 3)
		{
			coord.x = pos.x + x;
			coord.y = pos.y + y;
			set_pixel(v->tex, color, coord);
			x++;
		}
		y++;
		x = 0;
	}
}

void	ft_draw_score_bar(t_v *v)
{
	Uint32	color;
	int		score_max;
	int		pct;
	int		avc;
	t_pos	pos;

	score_max = v->platx * v->platy;
	pct = ((100 * v->j1score) / score_max) + 1;
	pos.x = 1070;
	pos.y = 250;
	avc = 1;
	while (avc < 100)
	{
		color = (avc < pct) ? 0x00d9ffFF : 0x37a6adFF;
		ft_draw_piece_bar(v, pos, color);
		avc++;
		pos.x += 3;
	}

	pct = ((100 * v->j2score) / score_max) + 1;
	pos.x = 1070;
	pos.y = 450;
	avc = 1;
	while (avc < 100)
	{
		color = (avc < pct) ? 0xae45d9FF : 0x9c6ab0FF;
		ft_draw_piece_bar(v, pos, color);
		avc++;
		pos.x += 3;
	}
}

void	handle_keys(t_v *v, TTF_Font *police)
{
	const Uint8		*keys;

	keys = SDL_GetKeyboardState(NULL);

	ft_draw_grid(v, v->tex);
	ft_draw_case(v);
	update_image(v, v->tex);
	ft_draw_all_ttf(v, police);
	ft_draw_score_bar(v);
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
