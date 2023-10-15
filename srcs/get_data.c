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

		if ((in_dbl_quo  % 2 == 0) && line[i] == ',')
			num++;
		i++;
	}
	return (num);
}

void	chk_value_of_col(int fd)
{
	size_t	first_num;
	size_t	crnt_num;
	char	*line;

	line = get_next_line(fd);
	first_num = number_of_col(line);

	while(1)
	{

		line = get_next_line(fd);
			if (line == NULL)
		break;
		crnt_num = number_of_col(line);
		if (first_num != crnt_num)
		{
			close(fd);
			err_exit("ERROR: The number of columns does not match.");
		}
	}
}
