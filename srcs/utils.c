#include "../inc/readcsv.h"

void	err_exit(char *str)
{
	printf("%s\nerrno: %s\n",str ,strerror(errno));
	exit (1);
}


// int	is_delimiter(char c)
// {
// 	if (c == ',' || c == '\n' || c == '\0')
// 		return (1)
// 	return (0)
// }

size_t	head_space_size(char *str)
{
	size_t	i = 0;

	if (*str == '\n' || *str == '\0')
		return (0);

	if (*str == ',')
		str++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	printf("head: %zu\n", i);
	return (i);
}


size_t	bottom_space_size(char *str)
{
	size_t	i = 0;

	if (*str == ',' || *str == '\n' || *str == '\0')
		str--;
	if (*str == '"')
		str--;

	while (*str == ' '|| str[i] == '\t')
	{
		str--;
		i++;
	}
	// printf("bottom: %zu\n", i);
	return (i);
}
