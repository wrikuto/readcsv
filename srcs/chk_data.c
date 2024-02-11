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

int	chk_and_get_tablesize(t_tablesize *tbl_size, int fd)
{
	size_t		crnt_num;
	size_t		row = 1;
	char		*line;

	// fd = get_fd(arg);
	line = get_next_line(fd, GNL_CONSUME);
	tbl_size->col = number_of_col(line);
	tbl_size->row = 0;
	free(line);
	while(1)
	{
		line = get_next_line(fd, GNL_CONSUME);
		if (line == NULL || line[0] == '\0')
			break;
		if (line[0] == '\n')
			;
		else
		{
			crnt_num = number_of_col(line);
			if (tbl_size->col != crnt_num)
			{
				free(line);
				close(fd);
				return(-1);
			}
			row++;
		}
		free(line);
	}
	tbl_size->row = row;
	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		close(fd);
		perror("ERROR(GNL)");
		exit(-1);
	}
	return (0);
}

