#include <stdio.h>
#include <stdlib.h>

// void	set_char(char **line)
// {
// 	size_t	i = 0;
// 	size_t	j = 0;

// 	*line = malloc(sizeof(char) * 6);
// 	while (i < 5)
// 	{
// 		(*line)[i] = 'a';
// 		i++;
// 	}
// 	(*line)[i] = '\0';
// }

int main()
{
	int i = 0;
	char	(*line)[60];

	line = malloc(sizeof(char *) * 2);
	while (i < 5)
	{
		line[0][i] = 'a';
		i++;
	}
	(*line)[i] = '\0';
	i = 0;
	while (i < 5)
	{
		line[1][i] = 'b';
		i++;
	}
	(*line)[i] = '\0';

	// set_char(&line);
	printf("%s\n", line[0]);
	printf("%s\n", line[1]);
	free (line);
	return (0);
}