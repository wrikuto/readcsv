#include "../inc/readcsv.h"

int main(int argc, char **argv)
{
	t_tablesize tablesize;
	char	***data;

	if (argc == 2)
	{
		tablesize = chk_and_get_datasize(argv[1]);
		printf("%zu, %zu\n", tablesize.row, tablesize.col);
		data = get_data(fd, tablesize);
	}
	printf("sucsess\n");
	return (0);
}
