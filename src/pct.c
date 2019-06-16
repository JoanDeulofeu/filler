#include "filler.h"

// int		ft_pct(t_f *f, int x, int y)
// {
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
