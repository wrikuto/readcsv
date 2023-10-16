#include "../inc/readcsv.h"

char	***readcsv(char *filename)
{
	t_tablesize tablesize;
	char	***table;
	int fd;

	if (filename)
	{
		tablesize = chk_and_get_datasize(filename);
		fd = open(filename, O_RDONLY);
		table = get_data(fd, tablesize);
		close(fd);
		return (table);
	}
	else
		printf("need filename.\n");
	return (0);
}



// ---

// テスト用のmain


// int main()
// {
// 	// t_tablesize tablesize;
// 	char	***table;

// 	table = readcsv("./tests/ken.csv");
// 	print_table(table);
// 	free_table(table);
// 	// if (argc == 2)
// 	// {
// 	// 	tablesize = chk_and_get_datasize(argv[1]);
// 	// 	fd = open(argv[1], O_RDONLY);
// 	// 	table = get_data(fd, tablesize);
// 	// 	print_table(table);
// 	// 	free_table(table);
// 	// 	close(fd);
// 	// 	printf("\nsucsess\n");
// 	// }
// 	return (0);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q readcsv");
// }