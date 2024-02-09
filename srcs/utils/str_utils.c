#include "../../inc/readcsv.h"

void	skip_blank(char **line)
{
	if (*line == NULL)
		return ;
	while(isblank(**line))
		(*line)++;
}

