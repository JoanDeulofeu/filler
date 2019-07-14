#include "visu.h"

// int		ft_visu(t_v *v)
// {
// 	// char	*line = NULL;
//
// 	// while (get_next_line(0, &line) > 0)
// 	// {
// 	//
// 	// }
// 	// return(0);
// }

char	**ft_do_tab(t_v *f)
{
	int		x = 0;
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * f->platy)))
		return (0);
	while (x < f->platy)
	{
		if (!(tab[x] = (char*)malloc(sizeof(char) * f->platx + 1)))
			return (0);
		tab[x][f->platx] = '\0';
		x++;
	}
	return (tab);
}

int		ft_fill_lst(t_v *v, int lgn, char *line)
{
	int		x = 0;
	t_map	*tmp;
	int		lg;

	lg = ft_nbrlen(lgn);
	tmp = v->lst;
	// printf("line = %s, lg = %d\n", line, lg);
	// printf("list = %p\n", v->lst);
	while (tmp->next != NULL)
		tmp = tmp->next;

	while (x <= v->platx)
	{
		tmp->map[lgn][x] = line[x + lg + 1];
		x++;
		// if (x == v->platx)
			// printf("tour%d[%d] = %s\n", tmp->tour, lgn, tmp->map[lgn]);
	}
	return (0);
}

int		ft_add_list(t_v *v, int tour)
{
	t_map	*tmp;

	tmp = v->lst;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (!(tmp->next = (t_map*)malloc(sizeof(t_map) * 1)))
			exit(0);
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	else
	{
		if (!(v->lst = (t_map*)malloc(sizeof(t_map) * 1)))
			exit(0);
		v->lst->prev = NULL;
		tmp = v->lst;
	}
	tmp->tour = tour;
	v->last_round = tour;
	tmp->map = ft_do_tab(v);
	tmp->piece = NULL;
	tmp->next = NULL;
	// printf("list = %p   &&   tmp = %p\n", v->lst, tmp);
	return (0);
}

int		ft_init_visu(t_v *v)
{
	int		fd;
	int		tour;
	char	*line = NULL;

	fd = open("/Users/jgehin/42/Filler/test.txt", O_RDONLY);
	tour = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == 'P')
		{
			v->platy = ft_atoi(&line[11]);
			v->platx = ft_atoi(&line[8]);
			if (v->platx > 99 || v->platy > 99)
				exit (0); //pas d'impression de map >=100
			// ft_do_tab(v);
			// ft_draw_grid(v->tex);
			// update_image(v, v->tex);
		}
		if (line[0] == 'T')
		{
			tour = ft_atoi(&line[5]);
			ft_add_list(v, tour);
		}
		if (line[0] > 47 && line[0] < 58)
			ft_fill_lst(v, ft_atoi(&line[0]), line);
	}
	return (0);
}

int		ft_suite(void)
{
	t_v	v;

	v.window = NULL;
	v.renderer = NULL;
	v.tex = NULL;
	v.lst = NULL;
	v.platx = 0;
	v.platy = 0;
	v.j1score = 0;
	v.j2score = 0;
	v.casex = 0;
	v.casey = 0;
	v.init = 0;
	v.tour = 1;
	v.last_round = 1;
	v.play = FALSE;
	initialize_sdl(&v);
	ft_init_visu(&v);
	// ret = ft_visu(&v);
	event_handler(&v);
	return (0);
}

int		main(void)
{
	int ret = 0;

	ft_suite();
	return (ret);
}
