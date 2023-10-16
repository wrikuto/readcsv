#include "../inc/readcsv.h"

void	free_sub(char ***table, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(table[j]);
		j++;
	}
	free(table);
	err_exit("2nd malloc failed !");
}

void	free_table(char	***table)
{
	size_t	i = 0;
	size_t	j = 0;


	while (table[i] != NULL)
	{
		j = 0;
		while (table[i][j] != NULL)
		{
			free(table[i][j]);
			j++;
		}
		i++;
	}

	i = 0;
	while (table[i] != NULL)
	{
		free(table[i]);
		i++;
	}
	free(table);
}


void	err_exit(char *str)
{
	printf("%s\nerrno: %s\n",str ,strerror(errno));
	exit (1);
}

size_t	head_space_size(char *str)
{
	size_t	i = 0;

	if (*str == '\n' || *str == '\0')
		return (0);

	if (*str == ',')
		str++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}



// ダブルクォテーション内か判定
int	is_in_dbl(char *str)
{
	while (*str != '"')
	{
		str--;
		if (*str == ',')
			return (0);
	}
	return (1);
}



// size_t	bottom_space_size(char *str)
// {
// 	size_t	i = 0;

// 	if (*str == ',' || *str == '\n' || *str == '\0')
// 		str--;
// 	if (*str == '"')
// 		str--;

// 	while (*str == ' '|| str[i] == '\t')
// 	{
// 		str--;
// 		i++;
// 	}
// 	// printf("bottom: %zu\n", i);
// 	return (i);
// }


// // "で閉じられていたら1を返す
// size_t	is_back_dblquo(char *str)
// {
// 	size_t	i = 0;

// 	if (*str == ',' || *str == '\n' || *str == '\0')
// 		str--;
// 	while (*str == ' '|| str[i] == '\t')
// 		str--;
// 	if (*str == '"')
// 		return (1);
// 	return (0);
// }