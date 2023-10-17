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

void	print_selected(char ***table, size_t *row, size_t *col)
{
	size_t	i = 0;
	size_t	j = 0;

	i = row[0];
	
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