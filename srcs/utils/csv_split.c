#include "../../inc/readcsv.h"

ssize_t	ft_sublen(const char *str, char c)
{
	ssize_t	i = 0;
	ssize_t	len = 0;
	ssize_t	tail_count = 0;
	bool	in_quotes = false; // ダブルクォテーション内かどうかを追跡

	while (str[i] != '\0' && str[i] != '\n')
	{
		if(str[i] == '"')
			in_quotes = !in_quotes;
		else if (str[i] == c && !in_quotes)
			break;
		i++;
	}
	len = i;
	if (str[i - 1] != ' ' && str[i - 1] != '\t')
		return (len);
	while (1)
	{
		i--;
		if (i == -1)
			return (-1);
		if (str[i] != ' ' && str[i] != '\t')
			break;
		tail_count++;
	}
	return (len - tail_count);
}

size_t	count_cell(const char *str, char c)
{
	size_t	i;
	size_t	count;
	bool	in_quotes = false; // ダブルクォテーション内かどうかを追跡

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if(str[i] == '"')
			in_quotes = !in_quotes;
		else if (str[i] == c && !in_quotes)
			count++;
		i++;
	}
	count++;
	return (count);
}

void	set_sub(char const *str, char c, char (*cell_tmp)[MAX_CHAR], size_t sub_n)
{
	size_t	i = 0;
	size_t	j;
	ssize_t	sub_len = 0;
	bool	flag_notempty;

	while (i < sub_n)
	{
		j = 0;
		while (*str == ' ' || *str == '\t')
			str++;
		if (*str == c)
			cell_tmp[i][0] = '\0';
		else
		{
			sub_len = ft_sublen(str, c);
			if (sub_len == -1)
			{
				perror("sub_len fail!");
				exit (-1);
			}
			while (j < sub_len)
			{
				cell_tmp[i][j] = *str;
				j++;
				str++;
			}
			cell_tmp[i][j] = '\0';
			while (*str != '\0' && *str != '\n' && *str != c)
				str++;
		}
		if (*str == c)
			str++;
		i++;
	}
}

void	csv_split(char const *str, t_CSVdata *csv_data)
{
	size_t	sub_n;

	if (!str)
		return ;
	sub_n = count_cell(str, csv_data->separator);
	if (str[0] == '\0')
		return ;
	set_sub(str, csv_data->separator, csv_data->cell_tmp, sub_n);
	
}
