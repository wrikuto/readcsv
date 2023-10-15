#include "../inc/readcsv.h"

static int	chk_filename(char *str)
{
	str = strrchr(str, '.');
	if (str != NULL && strncmp(str, ".csv", 5) == 0)
		return (1);
	return (0);
}

int	get_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1 || chk_filename(argv) == 0)
	{
		close (fd);
		err_exit("ERROR: Invaild file name.");
	}
	return (fd);
}
