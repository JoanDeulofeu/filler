#include "filler.h"

int		ft_do_tab(t_f *f)
{
	int x = 0;
	FILE	*fichier = NULL;

	if (!(f->map = (char**)malloc(sizeof(char*) * f->platy)))
		return (0);
	while (x < f->platy)
	{
		if (!(f->map[x] = (char*)malloc(sizeof(char) * f->platx + 1)))
			return (0);
		f->map[x][f->platx] = '\0';
		x++;
	}
	fichier = fopen("test.txt", "a+");
	fprintf(fichier, "PLATEAU %d %d\n", f->platx, f->platy);
	fclose(fichier);
	return (0);
}

int		ft_do_piece(t_f *f)
{
	int x = 0;

	if (!(f->piece = (char**)malloc(sizeof(char*) * f->piecey)))
		return (0);
	while (x < f->piecey)
	{
		if (!(f->piece[x] = (char*)malloc(sizeof(char) * f->piecex + 1)))
			return (0);
		f->piece[x][f->piecex] = '\0';
		x++;
	}
	f->filling = 0;
	return (0);
}
