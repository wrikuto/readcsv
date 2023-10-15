#include "../inc/readcsv.h"

int main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = get_fd(argv[1]);
		chk_value_of_col(fd);
	}
	printf("sucsess\n");
	return (0);
}

