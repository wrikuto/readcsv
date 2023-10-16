#include "../inc/readcsv.h"



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

size_t	len_cellchar(char *str, size_t	in_dbl_quo)
{
	size_t	i = 0;

	if (in_dbl_quo >= 2 && is_in_dbl(str))
	{
		while (str[i] != '"')
			i++;
		while (str[i - 1] == ' ' || str[i - 1] == '\t')
			i--;
		printf("TEST: %zu\n", i);

	}
	else
	{
		while (str[i] != ',' && str[i] != '\n' && str[i] != '\0')
			i++;
		while (str[i - 1] == ' ' || str[i - 1] == '\t')
			i--;
	}
	return (i);
}

// 取得したlineから、各列の文字列の長さを取得する。
t_cellchar	*cellchar_len_posi(char *line, t_tablesize tablesize)
{
	t_cellchar	*cellchar = NULL;
	size_t		in_dbl_quo = 0;
	size_t		crnt = 0;
	size_t		i = 0;
	size_t		len = 0;

	cellchar = malloc(sizeof(t_cellchar) * tablesize.col);
	if (cellchar == NULL)
		err_exit("cellchar malloc failed!");

	// 先に先頭の空白を飛ばす
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
		// ダブルクォテーション内でなく、区切り文字であれば
		if ((in_dbl_quo % 2 == 0) && (line[i] == ',' ||  line[i] == '\n' || line[i] == '\0'))
		{
			cellchar[crnt].len = len_cellchar(&line[i - len - is_back_dblquo(&line[i])], in_dbl_quo);
			cellchar[crnt].posi = &line[i - len - is_back_dblquo(&line[i])];
			// 次の列の文字列の先頭の空白を飛ばす
			i += head_space_size(&line[i]);
			len = 0;
			crnt++;
		}
		else
			len++;

		if (line[i] == '\n' || line[i] == '\0')
			break ;
		i++;
	}
	return (cellchar);
}


// char	***get_data(int fd, t_tablesize tablesize)
// {
// 	char	***table = NULL;
// 	char	*line = NULL;
// 	t_cellchar	*cellchar = NULL;
// 	size_t	i = 0;
// 	size_t	j = 0;
// 	size_t	k = 0;

// 	table = init_table(tablesize);

// 	while (i < tablesize.col)
// 	{
// 		line = get_next_line(fd);
// 		j = 0;
// 		while (j < tablesize.row)
// 		{
// 			cellchar = cellchar_len_posi(line, tablesize);
// 			if (cellchar[j].len == 0)
// 			{
// 				table[i][j] = calloc(256, sizeof(char));
// 				break ;
// 			}
// 			table[i][j] = malloc(sizeof(char) * (cellchar[j].len + 1));
// 			table[i][j][cellchar[j].len] = '\0';
// 				k = 0;
// 			while (k < cellchar[j].len)
// 			{
// 				table[i][j][k] = *(cellchar[j].posi + k);
// 				k++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (table);
// }


			// printf("POSI: %s\n", &line[i - len - is_back_dblquo(&line[i])]);
			// printf("len: %zu\n", len_cellchar(&line[i - len - is_back_dblquo(&line[i])]));



// -----


int main()
{
	// char *line = "892,3,\"Kelly, Mr. James\",male,34.5,0,0,330911,7.8292,,Q";
	char *line = "892  ,  3  ,  \"   Kelly, Mr. James   \"   ,   male,34.5,0,0,330911,7.8292,,  \" Q \"   ";
	t_cellchar *data;
	t_tablesize tablesize;

	tablesize.col = 11;

	data = cellchar_len_posi(line, tablesize);

	// printf("%s", line);
	int i = 0;
	while (i < 11)
	{
		printf("%zu, %s\n", data[i].len, (data[i].posi));
		i++;
	}
	free (data);
	return (0);

}
