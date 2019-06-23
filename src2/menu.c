#include "visu.h"

int		ft_draw_menu(t_v *v)
{
	Uint32	color;
	t_pos	coord;

	coord.x = HEIGHT + 20;
	coord.y = 20;
	while (coord.y < HEIGHT - 20)
	{
		while (coord.x < WIDTH - 20)
		{
			if (coord.x == HEIGHT + 20 || coord.x == WIDTH - 21
				|| coord.y == 20 || coord.y == HEIGHT - 21)
				color = 0xa1ffffFF;
			else
				color = 0x282828FF;
			set_pixel(v->tex, color, coord);
			coord.x++;
		}
		coord.x = HEIGHT + 20;
		coord.y++;
	}
	return (0);
}
