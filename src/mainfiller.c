#include "filler.h"

int		ft_fill_map(t_f *f, int lgn, char *line)
{
	int		x = 0;
	FILE	*fichier = NULL;

	while (x < f->platx)
	{
		f->map[lgn][x] = line[x + 4];
		if (line[x + 4] == f->me && f->me_originx == -1)
		{
			f->me_originx = x;
			f->me_originy = lgn;
			// ft_test(f->me_originx, f->me_originy);
		}
		else if (line[x + 4] == f->him && f->him_originx == -1)
		{
			f->him_originx = x;
			f->him_originy = lgn;
			// ft_test(f->him_originx, f->him_originy);
		}
		x++;
		fichier = fopen("test.txt", "a+");
		if (x == f->platx)
		{
			if (lgn == 0)
				fprintf(fichier, "TOUR %d\n", f->round++);
			fprintf(fichier, " %s\n", f->map[lgn]);
		}
		fclose(fichier);
	}
	return (0);
}

int		ft_fill_piece(t_f *f, char *line)
{
	int		x = 0;
	// FILE	*fichier = NULL;

	while (x < f->piecex)
	{
		f->piece[f->filling][x] = line[x];
		x++;

		// ft_test(f->me_originx, f->me_originy);
		// ft_test(f->him_originx, f->him_originy);
		// fichier = fopen("test.txt", "a+");
		// if (x == f->piecex)
		// 	fprintf(fichier, "PIECE %d = %s\n", f->filling, f->piece[f->filling]);
		// fclose(fichier);
	}
	f->filling++;
	if (f->filling == f->piecey) //fini de remplir la piece
		ft_find_place(f);
	return (0);
}

int		ft_filler(t_f *f)
{
	char	*line = NULL;

	while (get_next_line(0, &line) > 0)
	{
		// FILE	*fichier = NULL;
		// fichier = fopen("test.txt", "a+");
		// fprintf(fichier, "# %s\n", line);
		// fclose(fichier);

		if (line[0] == '$')
		{
			f->player = line[10] - 48;
			f->me = f->player == 1 ? 'O' : 'X';
			f->him = f->player == 1 ? 'X' : 'O';
		}

		if (line[0] == 'P' && line[1] == 'l' && f->init == FALSE)
		{
			f->platy = ft_atoi(&line[8]);
			f->platx = ft_atoi(&line[11]);
			ft_do_tab(f);
			f->init = TRUE;
		}

		if (line[0] == 'P' && line[1] == 'i')
		{
			ft_free_2d_tab(f->piece, f->piecey);
			f->piecey = ft_atoi(&line[6]);
			f->piecex = ft_atoi(&line[8]);
			ft_do_piece(f);
		}

		if (line[0] > 47 && line[0] < 58)
			ft_fill_map(f, ft_atoi(&line[0]), line);

		if (line[0] == '*' || line[0] == '.')
			ft_fill_piece(f, line);
		// sleep(2);
	}
	return(0);
}

int		main(void)
{
	int ret;
	t_f f;
	t_pos pos;

	ret = 0;
	f.me_originx = -1;
	f.me_originy = -1;
	f.him_originx = -1;
	f.him_originy = -1;
	f.platx = 0;
	f.platy = 0;
	f.piecex = 0;
	f.piecey = 0;
	f.player = 1;
	f.round = 1;
	f.map = NULL;
	f.piece = NULL;
	f.init = FALSE;
	f.init_touch = FALSE;
	f.pos = &pos;
	f.pos->x = 0;
	f.pos->y = 0;
	f.pos->pct = 0;

	ret = ft_filler(&f);
	return (ret);
}
