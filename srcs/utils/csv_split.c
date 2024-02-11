
#include "../../inc/readcsv.h"

void	free_split(char **ret, size_t i)
{
	size_t	j;

	j = 0;
	if (i == 0)
	{
		while (ret[j] != NULL)
			free (ret[j++]);
	}
	else
	{
	while (j < i)
			free(ret[j++]);
	}
	free(ret);
}

// 空の時に0を返していることに注意
static bool	is_empty(const char *str, char	c)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == c || *str == '\0' || *str == '\n')
		return (false);
	return (true);
}

size_t	ft_sublen(const char *str, char c)
{
	size_t	i;
	bool	in_quotes = false; // ダブルクォテーション内かどうかを追跡

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if(str[i] == '"')
			in_quotes = !in_quotes;
		else if (str[i] == c && !in_quotes)
			break;
		i++;
	}
	return (i);
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

char	**set_sub(char const *str, char c, char **ret, size_t sub_n)
{
	size_t	i = 0;
	size_t	j;
	size_t	sub_len = 0;
	bool 	in_quotes = false; // ダブルクォテーション内かどうかを追跡
	bool	flag_notempty;

	while (i < sub_n)
	{
		j = 0;
		flag_notempty = is_empty(str, c);
		sub_len = ft_sublen(str, c);
		ret[i] = malloc(sizeof(char) * (sub_len * flag_notempty  + 1));
		if (ret[i] == NULL)
		{
			free_split(ret, i);
			return (NULL);
		}
		while (j < sub_len)
		{
			ret[i][j] = *str;
			j++;
			str++;
		}
		ret[i][j] = '\0';
		if (flag_notempty == 0)
		{
			while (*str != '\0' && *str != '\n' && *str != c)
				str++;
		}
		if (*str == c)
			str++;
		i++;
	}
	return (ret);
}


char	**csv_split(char const *s, char c)
{
	size_t	sub_n;
	char	**ret;

	if (!s)
		return (NULL);
	sub_n = count_cell(s, c);
	ret = malloc(sizeof(char *) * (sub_n + 1));
	if (ret == NULL)
		return (NULL);
	if (s[0] == '\0')
		return (ret);
	ret[sub_n] = NULL;
	ret = set_sub(s, c, ret, sub_n);
	return (ret);
}

// void	csv_split(char const *s, t_CSVdata *csv_data)
// {
// 	size_t	sub_n;
// 	char	**ret;

// 	if (!s)
// 		return (NULL);
// 	sub_n = count_cell(s, csv_data->separator);
// 	ret = malloc(sizeof(char *) * (sub_n + 1));
// 	if (ret == NULL)
// 		return (NULL);
// 	if (s[0] == '\0')
// 		return (ret);
// 	ret[sub_n] = NULL;
// 	ret = set_sub(s, csv_data->separator, ret, sub_n);
// 	return (ret);
// }

// int main()
// {
// 	char	**str;
// 	char	*moji = "892,3,\"Kelly, Mr. \"\"James\"\"\",male,34.5,0,0,330911,7.8292,B114514,Q";
// 	int i = 0;

// 	str = csv_split(moji, ',');
// 	if (str == NULL)
// 	{
// 		printf("ERROR!\n");
// 		return (1);
// 	}
// 	while (str[i] != NULL)
// 	{
// 		printf("%s\n", str[i]);
// 		i++;
// 	}
// 	free_split(str, 0);

// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }