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
	// ft_create_ttf_texture("sdl cest de la merde", 1100, 900, v);
	// txt = ft_write_menu(v);
	return (0);
}
