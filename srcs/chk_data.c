#include "../inc/readcsv.h"

static size_t	number_of_col(char	*line)
{
	size_t	i = 0;
	size_t	in_dbl_quo  = 0;
	size_t	num = 0;

	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == '"')
			in_dbl_quo++;

		if ((in_dbl_quo % 2 == 0) && line[i] == ',')
			num++;
		i++;
	}
	return (num + 1);
}

t_tablesize	chk_and_get_datasize(char *arg)
{
	t_tablesize	tbl_size;
	size_t		crnt_num;
	size_t		row = 1;
	char		*line;
	int

	fd = get_fd(arg);
	line = get_next_line(fd);
	tbl_size.col = number_of_col(line);
	tbl_size.row = 0;
	free(line);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\0')
			break;
		if (line[0] == '\n')
			;
		else
		{
			crnt_num = number_of_col(line);
			if (tbl_size.col != crnt_num)
			{
				// close(fd);
				printf("ERROR: The number of columns does not match.");
			}
			row++;
		}
		free(line);
	}
	close(fd);
	tbl_size.row = row;
	return (tbl_size);
}

