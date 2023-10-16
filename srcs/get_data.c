#include "../inc/readcsv.h"



char	***init_table(t_tablesize tablesize)
{
	char	***table = NULL;
	// size_t	col_size;
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

// 取得したlineから、各列の文字列の長さを取得する。
t_cellchar	*cellchar_len_posi(char *line, t_tablesize tablesize)
{
	t_cellchar	*cellchar = NULL;
	char		*headtmp = NULL;
	size_t		in_dbl_quo = 0;
	size_t		crnt = 0;
	size_t		i = 0;
	size_t		len = 0;

	cellchar = malloc(sizeof(t_cellchar) * tablesize.col);
	if (cellchar == NULL)
		err_exit("cellchar malloc failed!");

	// 先に先頭の空白を飛ばす
	line += head_space_size(line);
	headtmp = &line[i];
	while (1)
	{
		if (line[i] == '"')
		{
			if (line[i + 1] == '"')
				i++;
			else
			{
			in_dbl_quo++;
			i++;
				if (in_dbl_quo % 2 == 1)
				{
					i += head_space_size(&line[i]);
					headtmp = &line[i];
				}
			}
		}
		// ダブルクォテーション内でなく、区切り文字であれば
		if ((in_dbl_quo % 2 == 0) && (line[i] == ',' ||  line[i] == '\n' || line[i] == '\0'))
		{
			cellchar[crnt].len = len;
			cellchar[crnt].posi = headtmp;
			// 次の列の文字列の先頭の空白を飛ばす
			i += head_space_size(&line[i]);
			headtmp = &line[i + 1];
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


char	***get_data(int fd, t_tablesize tablesize)
{
	char	***table = NULL;
	char	*line = NULL;
	t_cellchar	*cellchar = NULL;
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = 0;

	table = init_table(tablesize);

	while (i < tablesize.row)
	{
		line = get_next_line(fd);
		// printf("%s  \n", line);
		j = 0;
		while (j < tablesize.col)
		{
			cellchar = cellchar_len_posi(line, tablesize);

			if (cellchar[j].len == 0)
			{
				table[i][j] = calloc(256, sizeof(char));
				if (table[i][j] == NULL)
					err_exit("calloc fail get_data");
				break ;
			}

			table[i][j] = malloc(sizeof(char) * (cellchar[j].len + 1));
			table[i][j][cellchar[j].len] = '\0';
				k = 0;
				// printf("%s  ", cellchar[j].posi);
			while (k < cellchar[j].len)
			{
				table[i][j][k] = *(cellchar[j].posi + k);
				if (*(cellchar[j].posi + k) == '"' && *(cellchar[j].posi + k + 1) == '"')
					cellchar[j].posi++;
				k++;
			}
			j++;
		}
		i++;
	}
	close(fd);
	return (table);
}



// -----


// int main()
// {
// 	// char *line = "892,3,\"Kelly, Mr. James\",male,34.5,0,0,330911,7.8292,,Q";
// 	char *line = "927,3,\"Katavelas, Mr. Vassilios (Catavelas Vassilios\"\")\"\"\",male,18.5,0,0,2682,7.2292,,C";
// 	t_cellchar *data;
// 	t_tablesize tablesize;

// 	tablesize.col = 11;

// 	data = cellchar_len_posi(line, tablesize);

// 	// printf("%s", line);
// 	int i = 0;
// 	while (i < 11)
// 	{
// 		printf("%zu, %s\n", data[i].len, (data[i].posi));
// 		i++;
// 	}
// 	free (data);
// 	return (0);

// }


// size_t	len_cellchar(char *str, size_t	in_dbl_quo)
// {
// 	size_t	i = 0;

// 	if (in_dbl_quo >= 2 && is_in_dbl(str))
// 	{
// 		while (str[i] != '"' || (str[i] == '"' && str[i + 1] == '"'))
// 			i++;
// 		while (str[i - 1] == ' ' || str[i - 1] == '\t')
// 			i--;
// 	}
// 	else
// 	{
// 		while (str[i] != ',' && str[i] != '\n' && str[i] != '\0')
// 			i++;
// 		while (str[i - 1] == ' ' || str[i - 1] == '\t')
// 			i--;
// 	}
// 	return (i);
// }