#include "../inc/readcsv.h"

// 行列のメモリ確保
static t_table	**init_table(t_tablesize tbl_size)
{
	t_table	**table = NULL;
	size_t	i = 0;

	table = malloc(sizeof(t_table *) * (tbl_size.row + 1));
	if (table == NULL)
		err_exit("1st malloc failed!");
	table[tbl_size.row] = NULL;
	while (i < tbl_size.row)
	{
		table[i] = malloc(sizeof(t_table *) * (tbl_size.col + 1));
		if (table[i] == NULL)
			err_exit("fail init!");
		// table[i][tbl_size.col] = NULL;
		i++;
	}

	return (table);
}

// 取得した行から、各列の文字列の長さを取得する。
static t_cellchar	*cellchar_len_posi(char *line, t_tablesize tablesize)
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
		// ダブルクォテーションの判定と処理
		if (line[i] == '"')
		{
			if (line[i + 1] == '"')
				i++;
			else
			{
				in_dbl_quo++;
				if (in_dbl_quo % 2 == 1)
					headtmp = &line[i];
			}
		}
		// 区切りの処理
		if ((in_dbl_quo % 2 == 0) && (line[i] == ',' || line[i] == '\n' || line[i] == '\0'))
		{
			if (is_blank(headtmp))
				len = 0;
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


t_table	**get_data(int fd, t_tablesize tbl_size)
{
	t_table	**table;
	char	*line = NULL;
	t_cellchar	*cellchar = NULL;
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = 0;

	table = init_table(tbl_size);

	while (i < tbl_size.row)
	{
		line = get_next_line(fd);
		if (line[0] == '\n')
			;
		else
		{
			j = 0;
			while (j < tbl_size.col)
			{
				cellchar = cellchar_len_posi(line, tbl_size);
				if (cellchar[j].len == 0)
				{
					table[i][j].value.str_val = calloc(16, sizeof(char));
					if (table[i][j].value.str_val == NULL)
						err_exit("calloc fail get_data");
					strcpy(table[i][j].value.str_val, "MISSING\0");
				}
				else
				{
					table[i][j].value.str_val = malloc(sizeof(char) * (cellchar[j].len + 1));
					if (table[i][j].value.str_val == NULL)
						err_exit("calloc fail get_data");
					table[i][j].value.str_val[cellchar[j].len] = '\0';
						k = 0;

					while (k < cellchar[j].len)
					{
						table[i][j].value.str_val[k] = *(cellchar[j].posi + k);
						if (*(cellchar[j].posi + k) == '"' && *(cellchar[j].posi + k + 1) == '"')
							cellchar[j].posi++;
						k++;
					}
				}
				free(cellchar);
				j++;
			}
			i++;
		}
		free(line);
	}
	return (table);
}



// -----


// int main()
// {
// 	char *line = "892,3,   \"Kelly, Mr. James\"  ,male,34.5,0,0,330911,7.8292,,Q";
// 	// char *line = "927,3,\"Katavelas, Mr. Vassilios (Catavelas Vassilios\"\")\"\"\",male,18.5,0,0,2682,7.2292,,C";
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

