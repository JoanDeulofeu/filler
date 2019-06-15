#include "filler.h"

int main(void)
{
	char *line = NULL;

	ft_putstr("123lol456\n");
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr("ptdrlol\n");
		printf("RESULTAT = |%s|\n", line);
	}

	return (0);
}
