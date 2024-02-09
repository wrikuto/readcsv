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
	int		fd;
	// size_t	i = 0;

	if (*line == '\0')
		return ;
	filename = ft_strtrim(line, " \t");
	if (filename == NULL)
		perror("malloc (interpret)");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("wrong filename.");
		free (filename);
		return ;
	}
	else
	{

		csv_data->tbl_size = chk_and_get_datasize(filename);
		get_datatype(get_next_line(fd), csv_data->tbl_size);
		// csv_data = readcsv(filename, csv_data);
		printf("TEST row: %zu\n", csv_data->tbl_size.row);
		close(fd);
	}
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
	printf("readcsv for C. welcome.\n\nenter filename.\n");
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