#include "filler.h"

// int		ft_place_piece(t_f *f, int x, int y)
// {
// 	int		px = -1;
// 	int		py = -1;
// 	int		svx = x;
//
// 	while (++py < f->piecey)
// 	{
// 		while (++px < f->piecex)
// 		{
// 			if (f->piece[py][px] == '*')
// 			{
// 				if (f->map[y][x] == '.')
// 					f->map[y][x] = 'T';
// 			}
// 			x++;
// 		}
// 		px = -1;
// 		x = svx;
// 		y++;
// 	}
// 	return (0);
// }
//
// int		ft_remove_piece(t_f *f, int x, int y)
// {
// 	int svx = x;
// 	int svy = y;
//
// 	while (y < svy + f->piecey)
// 	{
// 		while (x < svx + f->piecex)
// 		{
// 			if (f->map[y][x] = 'T')
// 				f->map[y][x] == '.';
// 			x++;
// 		}
// 		x = svx;
// 		y++;
// 	}
// 	return (0);
// }
//
// char	ft_dist_me(t_f *f, int casex, int casey)
// {
// 	int		dist_x = 0;
// 	int		dist_y = 0;
// 	int		dist = 10000000;
// 	int		x = 0;
// 	int		y = 0;
//
// 	while (y < HEIGHT)
// 	{
// 		while (x < WIDTH)
// 		{
// 			if (f->map[y][x] == f->me || f->map[y][x] == 'T')
// 			{
// 				dist_x = casex > x ? casex - x : x - casex;
// 				dist_y = casey > y ? casey - y : y - casey;
// 				if (dist_x + dist_y < dist)
// 					dist = dist_x + dist_y;
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	return (dist);
// }
//
// char	ft_dist_him(t_f *f, int casex, int casey)
// {
// 	int		dist_x = 0;
// 	int		dist_y = 0;
// 	int		dist = 10000000;
// 	int		x = 0;
// 	int		y = 0;
//
// 	while (y < HEIGHT)
// 	{
// 		while (x < WIDTH)
// 		{
// 			if (f->map[y][x] == f->him)
// 			{
// 				dist_x = casex > x ? casex - x : x - casex;
// 				dist_y = casey > y ? casey - y : y - casey;
// 				if (dist_x + dist_y < dist)
// 					dist = dist_x + dist_y;
// 			}
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	return (dist);
// }
//
// int		ft_algo(t_f *f)
// {
// 	int		me = 0;
// 	int		him = 0;
// 	int		x = 0;
// 	int		y = 0;
//
// 	while (y < HEIGHT)
// 	{
// 		while (x < WIDTH)
// 		{
// 			if (f->map[y][x] == f->me)
// 				me++;
// 			else if (f->map[y][x] == f->him)
// 				him++;
// 			else if (ft_dist_me(f, x, y) < ft_dist_him(f, x, y))
// 				me++;
// 			else
// 				him++;
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	return ((100 * me) / (f->platx * f->platy));
// }
//
// int		ft_pct(t_f *f, int x, int y)
// {
// 	int pct;
//
// 	ft_place_piece(f, x, y);
// 	pct = ft_algo(f);
// 	ft_remove_place(f, x, y);
// 	return (pct);
// }

int		ft_touch(t_f *f, int x, int y)
{
	int dist1;
	int dist2;
	int pct;

	dist1 = ft_abs(f->him_originx - x) + ft_abs(f->him_originy - y);
	dist2 = ft_abs(f->him_originx - (x + f->piecex)) + ft_abs(f->him_originy - (y + f->piecey));
	dist1 = (dist1 < dist2) ? dist1 : dist2;
	pct = 100 - ((dist1 * 100) / (f->platx + f->platy + 1)); //+1 protection arrondi, on sait jamais.

	// FILE	*fichier = NULL;
	// fichier = fopen("test.txt", "a+");
	// fprintf(fichier, "Pct = %d\n", pct);
	// fclose(fichier);
	return (pct);
}
