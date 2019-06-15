#include "filler.h"

int		ft_fill_map(t_f *f, int lgn, char *line)
{
	int		x = 0;
	FILE	*fichier = NULL;

	while (x < f->platx)
	{
		f->map[lgn][x] = line[x + 4];
		x++;
		fichier = fopen("test.txt", "a+");
		if (x == f->platx)
			fprintf(fichier, "LA LIGNE[%d] = %s\n", lgn, f->map[lgn]);
		fclose(fichier);
	}
	return (0);
}

int		ft_filler(t_f *f)
{
	char	*line = NULL;
	FILE	*fichier = NULL;

	while (get_next_line(0, &line) > 0)
	{
		fichier = fopen("test.txt", "a+");
		fprintf(fichier, "%s\n", line);
		fclose(fichier);

		if (line[0] == '$')
			f->player = line[10] - 48;

		if (line[0] == 'P' && line[1] == 'l' && f->init == FALSE)
		{
			f->platy = ft_atoi(&line[8]);
			f->platx = ft_atoi(&line[11]);
			ft_do_tab(f);
			f->init = TRUE;
		}

		if (line[0] == 'P' && line[1] == 'i')
		{
			//algo placement piece
		}

		if (line[0] > 47 && line[0] < 58)
			ft_fill_map(f, ft_atoi(&line[0]), line);

	}
	return(0);
}

int		main(void)
{
	int ret;
	t_f f;

	ret = 0;
	f.platx = 0;
	f.platy = 0;
	f.player = 0;
	f.map = 0;
	f.init = FALSE;

	ret = ft_filler(&f);
	return (ret);
}
