#include "filler.h"

int	ft_do_tab(t_f *f)
{
	int x = 0;

	if (!(f->map = (char**)malloc(sizeof(char*) * f->platx)))
		return (0);
	while (x < f->platx)
	{
		if (!(f->map[x] = (char*)malloc(sizeof(char) * f->platy)))
			return (0);
		x++;
	}
	return (0);
}

int		ft_filler(t_f *f)
{
	char	*line = NULL;
	FILE	*fichier = NULL;
	(void)f;


	while (get_next_line(0, &line) > 0)
	{
		fichier = fopen("test.txt", "a+");
		fprintf(fichier, "%s\n", line);
		fclose(fichier);

		if (line[0] == '$')
			f->player = line[10] - 48;

		if (line[0] == 'P' && line[1] == 'l' && f->init == FALSE)
		{
			f->platx = ft_atoi(&line[8]);
			f->platy = ft_atoi(&line[11]);
			ft_do_tab(f);
			f->init = TRUE;
		}

		if (line[0] == 'P' && line[1] == 'i')
		{
			//algo placement piece
		}

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
