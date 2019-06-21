#include "visu.h"

void	ft_gridx(t_texture *tex, t_pos *orig, t_pos *dest, t_pos *coord)
{
	int			x;
	int			y;
	int			espy;
	Uint32		color = 0x4c4c4cFF;

	x = orig->x;
	y = orig->y;
	espy = 20;
	while (y <= dest->y)
	{
		while (x <= dest->x)
		{
			coord->x = x;
			coord->y = y;
			set_pixel(tex, color, *coord);
			x++;
		}
		x = orig->x;
		y += espy;
	}
}

void	ft_gridy(t_texture *tex, t_pos *orig, t_pos *dest, t_pos *coord)
{
	int			x;
	int			y;
	int			espx;
	Uint32		color = 0x4c4c4cFF;

	x = orig->x;
	y = orig->y;
	espx = 20;
	while (x <= dest->x)
	{
		while (y <= dest->y)
		{
			coord->x = x;
			coord->y = y;
			set_pixel(tex, color, *coord);
			y++;
		}
		y = orig->y;
		x += espx;
	}
}

void	ft_draw_grid(t_texture *tex)
{
	t_pos		orig;
	t_pos		dest;
	// int			nbcase = 32;
	t_pos		coord;

	// espx = (WIDTH - 20) / nbcase;
	// espy = (HEIGHT - 20) / nbcase;
	orig.x = 10;
	orig.y = 10;
	dest.x = WIDTH - 10;
	dest.y = HEIGHT - 10;

	ft_gridx(tex, &orig, &dest, &coord);
	ft_gridy(tex, &orig, &dest, &coord);

}
