
#include "../../inc/readcsv.h"

bool	is_blank_line(char	*line)
{
	while (*line != '\0' && *line != '\n')
	{
		if (*line != ' ' || *line != '\t')
			return (false);
		line++;
	}
	return (true);

}

static bool	set_datatype(char *line, t_CSVdata *csv_data)
{
	char	**split_line;
	char	*trim_str;
	size_t	i = 0;
	size_t	count = 0;
	errno = 0;

	split_line = csv_split(line, csv_data->separator);
	while (i < csv_data->tbl_size.col)
	{
		if (csv_data->value_type[i] != NONE)
			count++;
		else
		{
			trim_str = ft_strtrim(split_line[i], " \t");
			// printf("\nTRM: %s\n", trim_str);
			if (trim_str == NULL)
			{
				perror("malloc");
				exit(-1);
			}
			if (trim_str[0] == '\0')
				;
			else if (is_integer(trim_str) == 1)
				csv_data->value_type[i] = INT;
			else if (is_float(trim_str) == 1)
				csv_data->value_type[i] = DBL;
			else
				csv_data->value_type[i] = CHAR;

			if (csv_data->value_type[i] != NONE)
				count++;
			free(trim_str);
		}

		i++;
	}
	free_split(split_line, 0);
	if (count == csv_data->tbl_size.col)
		return (true);
	return (false);
}


void	get_datatype(int fd, t_CSVdata *csv_data)
{
	char		*line;
	char		**split_line;
	size_t		i = 0;
	// t_type		*value_type;
	
	csv_data->value_type = malloc(sizeof(t_type) * csv_data->tbl_size.col);
	while (i < csv_data->tbl_size.col)
	{
		csv_data->value_type[i] = NONE;
		i++;
	}
	i = 0;
	if (csv_data->is_header)
		free(get_next_line(fd, GNL_CONSUME));
	while(i < 100)
	{
		line = get_next_line(fd, GNL_CONSUME);
		// printf("TSET: %s\n", line);
		if (line == NULL)
			break;
		if (line[0] == '\n' || is_blank_line(line))
			;
		else
		{
			if (set_datatype(line, csv_data) == true)
			{
				free(line);
				break ;
			}
			i++;
		}
		free(line);
	}
	printf("COUNT: %zu\n", i);
	get_next_line(fd, GNL_RESET);
}

