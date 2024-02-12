
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
	
	size_t	i = 0;
	size_t	count = 0;
	errno = 0;

	csv_split(line, csv_data);
	if (csv_data->cell_tmp == NULL)
	{
		printf("cell_temp fail\n");
		exit (-1);
	}
	while (i < csv_data->tbl_size.col)
	{
		if (csv_data->value_type[i] != NONE)
			count++;
		else
		{
			if (csv_data->cell_tmp[i][0] == '\0')
				;
			else if (is_char(csv_data->cell_tmp[i]))
				csv_data->value_type[i] = CHAR;
			else if (is_integer(csv_data->cell_tmp[i]) == 1 && \
			csv_data->value_type[i] != DBL && csv_data->value_type[i] != CHAR)
				csv_data->value_type[i] = INT;
			else if (is_float(csv_data->cell_tmp[i]) == 1 && csv_data->value_type[i] != CHAR)
				csv_data->value_type[i] = DBL;
			if (csv_data->value_type[i] != NONE)
				count++;
		}
		i++;
	}
	if (count == csv_data->tbl_size.col)
		return (true);
	return (false);
}


void	get_datatype(int fd, t_CSVdata *csv_data)
{
	char		*line;
	size_t		i = 0;
	
	csv_data->value_type = malloc(sizeof(t_type) * csv_data->tbl_size.col);
	if (csv_data->value_type == NULL)
	{
		perror("value_type");
		exit (-1)
	}
	while (i < csv_data->tbl_size.col)
	{
		csv_data->value_type[i] = NONE;
		i++;
	}
	i = 0;
	if (csv_data->is_header)
		free(get_next_line(fd, GNL_CONSUME));
	while(i < 1000)
	{
		line = get_next_line(fd, GNL_CONSUME);
		if (line == NULL)
			break;
		if (line[0] == '\n' || is_blank_line(line))
			;
		else
		{
			if (set_datatype(line, csv_data) == true)
			{
				free(line);
				return ;
			}
			i++;
		}
		free(line);
	}
	get_next_line(fd, GNL_RESET);
}

