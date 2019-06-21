#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include <stdio.h> //MERDE
# include <stdlib.h> //MERDE
# define TRUE 1
# define FALSE 0

typedef struct		s_pos
{
	int				x;
	int				y;
	int				pct;
}					t_pos;

typedef struct		s_f
{
	char			me;
	char			him;
	int				round;
	int				me_originx;
	int				me_originy;
	int				him_originx;
	int				him_originy;
	int				platx;
	int				platy;
	int				player;
	int				init;
	int				init_touch;
	int				touch;
	int				piecex;
	int				piecey;
	int				filling;
	char			**map;
	char			**piece;
	t_pos			*pos;
}					t_f;

int					ft_do_tab(t_f *f);
int					ft_do_piece(t_f *f);
int					ft_free_2d_tab(char **tab, int taby);
int					ft_find_place(t_f *f);
int					ft_touch(t_f *f, int x, int y);

void				ft_test(int t1, int t2);

#endif
