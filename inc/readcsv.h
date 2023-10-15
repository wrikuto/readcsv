#ifndef READCSV_H
# define READCSV_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include "../get_next_line/get_next_line.h"
# include <errno.h>

int		get_fd(char *argv);
void	err_exit(char *str);
void	chk_value_of_col(int fd);

#endif
