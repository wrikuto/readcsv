#include "../inc/readcsv.h"

void	readcsv(char *filename, t_CSVdata *csv_data)
{
	int fd;

	if (filename)
	{
		csv_data->tbl_size = chk_and_get_datasize(filename);
		fd = open(filename, O_RDONLY);
		csv_data->table = get_data(fd, csv_data->tbl_size);
		close(fd);
		// return (table);
	}
	else
		printf("need filename.\n");
	// return (0);
}

void	interpret(char *line, t_CSVdata *csv_data)
{
	char	*filename;
	// size_t	i = 0;

	filename = ft_strtrim(line, " \t");
	if (filename == NULL)
		perror("malloc (interpret)");
	if (open(filename, O_RDONLY) == -1)
	{
		perror("wrong filename.");
		free (filename);
		return ;
	}
	// readcsv(filename, csv_data);
	free(filename);
}

// ---


int main(int argc, char **argv)
{
	t_CSVdata	csv_data;
	char		*line = NULL;

	// char	***table;
	// char	*cmd = NULL;

	if (argc != 1 || argv[0] == NULL)
		return (1);
	printf("readcsv for C. welcome.\n\nenter filename.");
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
		{
			write(STDERR_FILENO, "exit\n", 5);
			break ;
		}
		// if (*line)
		// 	add_history(line);
		interpret(line, &csv_data);
		free(line);
	}
	// readcsv(argv[1], &csv_data);
	// print_table(table);

	// free_table(table);

	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q readcsv");
}