#include "visu.h"

Uint32	ft_find_color(char player)
{
	Uint32	color;

	if (player == 'X')
		color = 0x40ffffFF;//     #40ffff
	else if (player == 'O')
		color = 0xae45d9FF;//     #ae45d9
	else
		color = 0x282828FF;//     #252525
	return (color);
}

int		ft_pose_case(t_v *v, int x, int y, char player)
{
	int		origx = 0;
	int		origy = 0;
	t_pos		coord;
	Uint32		color;

	color = ft_find_color(player);
	origx = (x * v->casex) + ((WIDTH - 400 - (v->platx * v->casex)) / 2) + 1;
	origy = (y * v->casey) + ((HEIGHT - (v->platy * v->casey)) / 2) + 1;
	x = origx;
	y = origy;
	// printf("coordx = %d | coordy = %d\n", x, y);
	if (v->tex->content[x + y * WIDTH] != color)
	{
		while (y < origy + v->casey - 1)
		{
			while (x < origx + v->casex - 1)
			{
				coord.x = x;
				coord.y = y;
				set_pixel(v->tex, color, coord);
				x++;
			}
			x = origx;
			y++;
		}
	}
	return (0);
}

int		ft_draw_case(t_v *v)
{
	int		x = 0;
	int		y = 0;
	t_map	*tmp;

	tmp = v->lst;
	while (tmp->tour != v->tour && tmp->next)
		tmp = tmp->next;
	while (y < v->platy)
	{
		while (x < v->platx)
		{
			if (tmp->map[y][x] == 'X')
				ft_pose_case(v, x, y, 'X');
			else if (tmp->map[y][x] == 'O')
				ft_pose_case(v, x, y, 'O');
			else if (tmp->map[y][x] == '.')
				ft_pose_case(v, x, y, '.');
			x++;
		}
		x = 0;
		y++;
	}

	return (0);
}
