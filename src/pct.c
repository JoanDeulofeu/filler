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
//
// 		}
// 	}
// 	return (0);
// }
//
// int		ft_pct(t_f *f, int x, int y)
// {
// 	ft_place_piece(f, x, y);
// 	//algo
// 	ft_remove_place(f, x, y);
// 	return (0);
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
