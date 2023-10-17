#include "../inc/readcsv.h"

void	free_table(char	***table)
{
	size_t	i = 0;
	size_t	j = 0;

	while (table[i] != NULL)
	{
		j = 0;
		while (table[i][j] != NULL)
		{
			free(table[i][j]);
			j++;
		}
		i++;
	}

	i = 0;
	while (table[i] != NULL)
	{
		free(table[i]);
		i++;
	}
	free(table);
}


void	print_table(char ***table)
{
	size_t	i = 0;
	size_t	j = 0;

	while (table[i] != NULL)
	{
		j = 0;
		while (table[i][j] != NULL)
		{
			printf("%s", table[i][j]);
			if (table[i][j + 1] != NULL)
				printf(" | ");
			j++;
		}
		printf("\n");
		i++;
	}
}

// void	print_selected(char ***table, size_t *row, size_t)
// {
// 	size_t	i = 0;
// 	size_t	j = 0;

// 	while (table[i] != NULL)
// 	{
// 		j = 0;
// 		while (table[i][j] != NULL)
// 		{
// 			printf("%s", table[i][j]);
// 			if (table[i][j + 1] != NULL)
// 				printf(" | ");
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }