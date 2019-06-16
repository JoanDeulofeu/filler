#include "filler.h"

int		ft_free_2d_tab(char **tab, int taby)
{
	int x = 0;

	if (tab == NULL)
		return (0);
	while (x < taby)
		ft_memdel((void **)&tab[x++]);
	ft_memdel((void **)&tab);
	return (0);
}

void	ft_test(int t1, int t2)
{
	FILE* fichier = NULL;

	fichier = fopen("test.txt", "a+");
	if (t1 == -42 && t2 == -42)
		fprintf(fichier, "- * - TESTTESTTESTTEST - * -\n");
	else if (t1 != -42 && t2 == -42)
		fprintf(fichier, "TEST1 = %d\n", t1);
	else
		fprintf(fichier, "TEST1 = %d      TEST2 = %d\n", t1, t2);
	fclose(fichier);
}
