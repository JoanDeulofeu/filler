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

int		ft_fill_map(t_v *v, int lgn, char *line)
{
	int		x = 0;
	FILE	*fichier = NULL;

	while (x < v->platx)
	{
		v->map[lgn][x] = line[x + 4];
		x++;
		fichier = fopen("test.txt", "a+");
		if (x == v->platx)
			fprintf(fichier, "LA LIGNE[%d] = %s\n", lgn, v->map[lgn]);
		fclose(fichier);
	}
	return (0);
}

int		ft_do_tab(t_v *f)
{
	int x = 0;

	if (!(f->map = (char**)malloc(sizeof(char*) * f->platy)))
		return (0);
	while (x < f->platy)
	{
		if (!(f->map[x] = (char*)malloc(sizeof(char) * f->platx + 1)))
			return (0);
		f->map[x][f->platx] = '\0';
		x++;
	}
	return (0);
}

void	event_handler(t_v *v)
{
	int		game;
	char	*line = NULL;

	game = 1;
	SDL_SetRelativeMouseMode(SDL_TRUE);
	while (game && get_next_line(0, &line) > 0)
	{
		// if (line[0] == 'P' && line[1] == 'l' && v->init == TRUE)
		// {
		//
		// 	update_image(v, v->tex);
		// }
		if (line[0] == 'P' && line[1] == 'l' && v->init == FALSE)
		{
			v->platy = ft_atoi(&line[8]);
			v->platx = ft_atoi(&line[11]);
			ft_do_tab(v);
			ft_draw_grid(v->tex);
			update_image(v, v->tex);
			v->init = TRUE;
		}
		if (line[0] > 47 && line[0] < 58)
			ft_fill_map(v, ft_atoi(&line[0]), line);
		while ((SDL_PollEvent(&(v->event))) != 0)
		{
			if (v->event.type == SDL_QUIT)
				game = 0;
			if (v->event.type == SDL_KEYDOWN
				&& keyboard_controls(v, v->event.key.keysym.sym) == 0)
				game = 0;
		}
		handle_keys(v);
	}
}


int		main(void)
{
	int ret = 0;
	t_v	v;

	initialize_sdl(&v);
	// ret = ft_visu(&v);
	event_handler(&v);
	return (ret);
}
