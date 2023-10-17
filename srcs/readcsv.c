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


int main(int argc, char **argv)
{
	// t_tablesize tablesize;
	char	***table;
	// char	*cmd = NULL;

	if (argc != 2)
		return (0);
	table = readcsv(argv[1]);
	print_table(table);

	// while (1)
	// {
	// 	cmd = readline("readcsv > ");
	// 	if (cmd == NULL)
	// 		return (0) ;
	// 	if (strcmp(cmd, "quit") == 0)
	// 	{
	// 		free(cmd);
	// 		break ;
	// 	}
	// }

	free_table(table);

	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q readcsv");
}