#include "../inc/readcsv.h"

void	print_table(char ***table)
{
	size_t	i = 0;
	size_t	j = 0;

	while (table[i] != NULL)
	{
		j = 0;
		while (table[i][j] != NULL)
		{
			printf("%s ,", table[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_tablesize tablesize;
	char	***table;
	int fd;

	if (argc == 2)
	{
		tablesize = chk_and_get_datasize(argv[1]);
		fd = open(argv[1], O_RDONLY);
		table = get_data(fd, tablesize);
		print_table(table);
		free_table(table);
		close(fd);
		printf("\nsucsess\n");
	}
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q readcsv");
}