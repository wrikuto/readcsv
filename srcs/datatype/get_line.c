
#include "../../inc/readcsv.h"

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
		if ((in_dbl_quo % 2 == 0) && (line[i] == ',' ||  line[i] == '\n' || line[i] == '\0'))
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

char	(*get_linedata(char *line, t_tablesize tbl_size))[RD_SIZE]
{
	char	(*cell)[RD_SIZE];
	t_cellchar	*cellchar = NULL;
	size_t	i = 0;
	size_t	j = 0;

	cell = malloc(sizeof(char[RD_SIZE]) * (tbl_size.col + 1));
	if (cell == NULL)
		err_exit("fail init!");

	cellchar = cellchar_len_posi(line, tbl_size);


	while (i < tbl_size.col)
	{
		if (cellchar[i].len == 0)
			cell[i][0] = '\0';
		else
		{
			cell[i][cellchar[i].len] = '\0';
			j = 0;
			while (j < cellchar[i].len)
			{
				cell[i][j] = *(cellchar[i].posi + j);
				if (*(cellchar[i].posi + j) == '"' && *(cellchar[i].posi + j + 1) == '"')
					j++;
				j++;
			}
		}
		i++;
	}
	
	return (cell);
}

t_type	*set_datatype(char (*cell)[RD_SIZE], t_tablesize tbl_size)
{
	size_t	i = 0;
	t_type	*data_type;
	errno = 0;

	data_type = malloc(sizeof(t_type) * tbl_size.col);
	while (i < tbl_size)
	{
		if ((*cell)[0] == '\0')
			data_type[i] = NONE;
		else if (is_str(*cell))
			data_type[i] = CHAR;
		else if (is_integer(*cell) == 1)
			data_type[i] = INT;
		else if (is_float(*cell) == 1)
			data_type[i] = DBL;
		else
		{
			perror("datatype fail.")
			exit (1)
		}
	}
	return (data_type);
}


t_type	*get_datatype(char *line, t_tablesize tbl_size)
{
	char	(*cell)[RD_SIZE];
	t_type		*data_type;
	t_cellchar	*cellchar = NULL;
	t_type		*data_type;

	
	cell = get_linedata(line, tbl_size);
	data_type = malloc(sizeof(t_type) * tbl_size.col);
	
	while (i < tbl_size.col)
	{
		printf("%s\n", cell[i]);
		i++;
	}
	free(cellchar);
	free (line);
	free (cell);
	return (data_type);
}

