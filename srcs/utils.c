#include "../inc/readcsv.h"

void	err_exit(char *str)
{
	printf("%s\nerrno: %s\n",str ,strerror(errno));
	exit (1);
}