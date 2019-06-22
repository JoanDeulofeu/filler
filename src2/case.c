#include "visu.h"

int		ft_pose_case(t_v *v, int x, int y, char player)
{
	int		origx = 0;
	int		origy = 0;
	t_pos		coord;
	Uint32		color;

	color = player == 'X' ? 0xe44b4bFF : 0xf0f050FF;
	origx = (x * v->casex) + ((WIDTH - (v->platx * v->casex)) / 2) + 1;
	origy = (y * v->casey) + ((WIDTH - (v->platy * v->casey)) / 2) + 1;
	x = origx;
	y = origy;
	// printf("coordx = %d | coordy = %d\n", x, y);
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
	return (0);
}
//     #e44b4b
//     #f0f050

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
			x++;
		}
		x = 0;
		y++;
	}

	return (0);
}
