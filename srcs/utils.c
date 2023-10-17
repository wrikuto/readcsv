#include "../inc/readcsv.h"

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

int	is_blank(char *str)
{
	size_t	i = 0;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '"')
	{
		i++;
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '"' && str[i + 1] != '"')
			return (1);
	}
	else if (str[i] == ',')
		return (1);
	return (0);
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