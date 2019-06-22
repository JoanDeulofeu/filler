#include "visu.h"

void	ft_gridx(t_texture *tex, t_pos *orig, t_pos *dest, int espy)
{
	int			x;
	int			y;
	Uint32		color = 0x4c4c4cFF;
	t_pos		coord;

	x = orig->x;
	y = orig->y;
	while (y <= dest->y)
	{
		while (x < dest->x)
		{
			coord.x = x;
			coord.y = y;
			set_pixel(tex, color, coord);
			x++;
		}
		x = orig->x;
		y += espy;
	}
}

void	ft_gridy(t_texture *tex, t_pos *orig, t_pos *dest, int espx)
{
	int			x;
	int			y;
	Uint32		color = 0x4c4c4cFF;
	t_pos		coord;

	x = orig->x;
	y = orig->y;
	while (x <= dest->x)
	{
		// printf("x = %d | desx = %d\n",x , dest->x);
		while (y < dest->y)
		{
			coord.x = x;
			coord.y = y;
			set_pixel(tex, color, coord);
			y++;
		}
		y = orig->y;
		x += espx;
		// printf("x = %d | desx = %d\n",x , dest->x);
	}
}

int		ft_find_esp(int nb_piece)
{
	int esp = 9;
	int res = 0;

	while (res < 1000)
		res = nb_piece * esp++;
	esp--;
	esp--;
	return (esp);
}

void	ft_draw_grid(t_v *v, t_texture *tex)
{
	t_pos		orig;
	t_pos		dest;
	int espx = 0;
	int espy = 0;

	espx = ft_find_esp(v->platx);
	espy = ft_find_esp(v->platy);
	v->casex = espx;
	v->casey = espy;
	orig.x = (WIDTH - (v->platx * espx)) / 2;
	orig.y = (HEIGHT - (v->platy * espy)) / 2;
	dest.x = orig.x + (v->platx * espx);
	dest.y = orig.y + (v->platy * espy);
	// printf("orix %d | oriy %d | desx %d | desy %d | espx %d | espy %d\n", orig.x, orig.y, dest.x, dest.y, espx, espy);

	ft_gridx(tex, &orig, &dest, espy);
	ft_gridy(tex, &orig, &dest, espx);

}
