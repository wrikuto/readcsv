#include "../../inc/readcsv/.h"



// void	set_valuetype(char **split_char, t_type *value_type)
// {
// 	size_t	i = 0;
// 	char	*cell[60]

// 	while (split_char[i] != NULL)
// 	{


// 	}
// }

int	get_valuetype(int fd, t_CSVdata *csv_data)
{
	char	*line;
	char	**split_char

	csv_data->value_type = malloc(sizeof(t_type) * csv_data->tbl_size.col);
	if (csv_data->value_type == NULL)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split_char = ft_split(line, ',');
		set_valuetype(split_char, csv_data->value_type);

		free (line)
	}
}