#include "../inc/readcsv.h"

int	readcsv(char *filename, t_CSVdata *csv_data)
{
	csv_data->fd = get_fd(filename);
	if (csv_data->fd == -1)
	{
		perror("ERROR");
		free (filename);
		return (-1);
	}
	else
	{
		csv_data->filename = filename;
		if (chk_and_get_tablesize(&(csv_data->tbl_size), csv_data->fd) == -1)
			printf("col not match.\n");
		else
		{

			get_datatype(csv_data->fd, csv_data);
			for (size_t i = 0; i < csv_data->tbl_size.col; i++)
			{
				if (csv_data->value_type[i] == NONE)
					printf("ENUM: NONE\n");
				if (csv_data->value_type[i] == CHAR)
					printf("ENUM: CHAR\n");
				if (csv_data->value_type[i] == INT)
					printf("ENUM: INT\n");
				if (csv_data->value_type[i] == DBL)
					printf("ENUM: DBL\n");
			}
			printf("col: %zu\n", csv_data->tbl_size.col);

			// get_data(csv_data->fd, csv_data);
		}
	}
	return (0);
}

int	interpret(char *line, t_CSVdata *csv_data)
{
	char	*filename;
	// size_t	i = 0;

	if (*line == '\0')
		return (1);
	errno = 0;
	if (strncmp(line, "exit", 4) == 0)
	{
		printf("bye.\n");
		exit(0);
		// return (1);
	}
	
	filename = ft_strtrim(line, " \t");
	if (filename == NULL)
	{
		perror("malloc (interpret)");
		return (-1);
	}
	if (readcsv(filename, csv_data) == -1)
		return (-1);
	// if (filename == NULL)
	// 	perror("malloc (interpret)");
	// fd = open(filename, O_RDONLY);
	// if (fd == -1)
	// {
	// 	perror("ERROR");
	// 	free (filename);
	// 	return (0);
	// }
	// else
	// {
	// 	if (chk_and_get_tablesize(&(csv_data->tbl_size), fd) == -1)
	// 		printf("col not match.\n");
	// 	else
	// 	{
			
	// 	}
	// }
	free(filename);
	close (csv_data->fd);
	return (0);
}

// ---


int main(int argc, char **argv)
{
	t_CSVdata	csv_data;
	char		*line = NULL;

	// char	***table;
	// char	*cmd = NULL;

	if (argv[0] == NULL)
		return (1);
	if (argc >= 2 && argv[1][0] == '0')
		csv_data.is_header = 0;
	else
		csv_data.is_header = 1;
	csv_data.separator = ',';
	printf("readcsv for C. welcome.\nenter filename.\n\n");
	while (1)
	{
		line = readline("RDcsv> ");
		if (line == NULL)
		{
			write(STDERR_FILENO, "exit\n", 5);
			break ;
		}
		// if (*line)
		// 	add_history(line);
		if (interpret(line, &csv_data) == 1) 
			break;
		free(line);
	}
	free(line);
	// readcsv(argv[1], &csv_data);
	// print_table(table);

	// free_table(table);

	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q readcsv");
}