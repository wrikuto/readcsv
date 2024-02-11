#include "../inc/readcsv.h"

static bool	chk_filename(char *filename)
{
	filename = strrchr(filename, '.');
	if (filename != NULL && strncmp(filename, ".csv", 5) == 0)
		return (true);
	return (false);
}

int	get_fd(char *filename)
{
	int	fd;

	if (chk_filename(filename) == 0)
		printf("ERROR: Invaild file type.\n");
	else
	{
		fd = open(filename, O_RDONLY);
		return (fd);
	}
	return (-1);
}
