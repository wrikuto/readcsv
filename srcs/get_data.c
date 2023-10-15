#include "../inc/readcsv.h"



void	free_sub(char ***ret, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(ret[j]);
		j++;
	}
	free(ret);
	err_exit("2nd malloc failed !");
}


char	***init_table(t_tablesize tablesize)
{
	char	***table = NULL;
	size_t	col_size;
	size_t	i = 0;

	table = malloc(sizeof(char *) * (tablesize.row + 1));
	if (table == NULL)
		err_exit("1st malloc failed!");
	table[tablesize.row] = NULL;
	while (i < tablesize.row)
	{
		table[i] = malloc(sizeof(char *) * (tablesize.col + 1));
		if (table[i] == NULL)
			free_sub(table, i);

		table[i][tablesize.col] = NULL;
		i++;
	}

	return (table);
}






size_t	*len_of_rowdata(char *line, t_tablesize tablesize)
{
	size_t	*sublen = NULL;
	size_t	in_dbl_quo = 0;
	size_t	sub_posi = 0;
	size_t	i = 0;
	size_t	len = 0;

	sublen = malloc(sizeof(size_t) * tablesize.col);
	if (sublen == NULL)
		err_exit("int malloc failed!");

	line += head_space_size(line);
	while (1)
	{
		if (line[i] == '"')
		{
			in_dbl_quo++;
			i++;
			if (in_dbl_quo % 2 == 1)
				i += head_space_size(&line[i]);
		}
		if ((in_dbl_quo % 2 == 0) && (line[i] == ',' || line[i] == '\n' || line[i] == '\0'))
		{
			sublen[sub_posi] = len - bottom_space_size(&line[i]);
			i += head_space_size(&line[i]);
			len = 0;
			sub_posi++;
		}
		else
			len++;

		if (line[i] == '\n' || line[i] == '\0')
			break ;
		i++;
	}
	return (sublen);
}

// -----
int main()
{
	// char *line = "892,3,\"Kelly, Mr. James\",male,34.5,0,0,330911,7.8292,,Q";
	char *line = "    PassengerId  ,\"   Pclass   \",Name,Sex,Age,SibSp   ,Parch,Ticket,Fare,Cabin,Embarked    ";
	size_t *data;
	t_tablesize tablesize;

	tablesize.col = 11;

	data = len_of_rowdata(line, tablesize);

	// printf("%s", line);
	int i = 0;
	while (i < 11)
	{
		printf("%zu\n", data[i]);
		i++;
	}
	free (data);
	return (0);

}

char	***get_data(int fd, t_tablesize tablesize)
{
	char	***table = NULL;
	char	*line;
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = 0;

	table = init_table(tablesize);

	while (i < tablesize.col)
	{
		j = 0;
		while (j < tablesize.row)
		{
			k = 0;
			// table[i][j] = malloc(sizeof(char) * )
			while (k < 42)
			{

			}
			j++;
		}
		i++;
	}

	return (table);
}


// char	*get_columns(char ***data, int fd)
// {
// 	size_t	j = 0;

// 	while ()
// }