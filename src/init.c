#include "filler.h"

int	ft_do_tab(t_f *f)
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
