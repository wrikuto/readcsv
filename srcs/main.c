#include "../inc/readcsv.h"

void	print_table(char ***table)
{
	int	i = 0;
	int j = 0
	// int	k = 0;

	while (table[i] != NULL)
	{
		j = 0;
		while (table[i][j] != NULL)
		{
			printf("CHK: %s, ", table[i][j]);
			j++
		}
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_tablesize tablesize;
	char	***table;

	if (argc == 2)
	{
		tablesize = chk_and_get_datasize(argv[1]);
		printf("%zu, %zu\n", tablesize.row, tablesize.col);
		table = get_data(fd, tablesize);
		print_table(table);
	}
	printf("sucsess\n");
	return (0);
}
