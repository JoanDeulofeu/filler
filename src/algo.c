#include "filler.h"

int		ft_worst_place(t_f *f, int x, int y)
{
	int pct;

	// if (f->touch == TRUE)
	// 	// pct = ft_pct(f, x, y);
	// 	pct = 10;
	// else
		pct = ft_touch(f, x, y);
	if (pct > f->pos->pct)
	{
		// ft_test(-42, -42);
		if (f->pos->pct > 90)
			f->touch = TRUE;
		f->pos->x = x;
		f->pos->y = y;
		f->pos->pct = pct;
	}
	return (0);
}

int		ft_check_pos(t_f *f, int x, int y)
{
	int		px = -1;
	int		py = -1;
	int		is_o = 0;
	int		is_x = 0;
	int		svx = x;
	int		svy = y;

	while(++py < f->piecey)
	{
		while (++px < f->piecex)
		{
			if (f->piece[py][px] == '.')
				;
			else if (f->map[y][x] == f->him)
				is_o++;
			else if (f->map[y][x] == f->me)
				is_x++;
			x++;
		}
		x = svx;
		++y;
		px = -1;
	}

	// ft_test(svx, svy);
	// ft_test(is_o, is_x);
	// FILE	*fichier = NULL;
	// fichier = fopen("test.txt", "a+");
	// fprintf(fichier, "\n");
	// fclose(fichier);

	if (is_o == 0 && is_x == 1)
		ft_worst_place(f, svx, svy);
	return (0);
}

int		ft_find_place(t_f *f)
{
	int		x = -1;
	int		y = -1;
	int		checkx = f->platx - (f->piecex - 1);
	int		checky = f->platy - (f->piecey - 1);

	while (++y < checky)
	{
		while (++x < checkx)
		{
			ft_check_pos(f, x, y);
		}
		x = -1;
	}
	x = f->pos->x;
	y = f->pos->y;
	// FILE* fichier = NULL;
	// fichier = fopen("test.txt", "a+");
	// fprintf(fichier, "PUSH  x%d y%d\n", x, y);
	// fclose(fichier);
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	// if (f->pos->pct > 90)
	// 	sleep(5);
	f->pos->pct = 0;
	// sleep(1);
	return (0);
}
