#ifndef READCSV_H
# define READCSV_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include "../get_next_line/get_next_line.h"
# include <errno.h>

typedef struct s_tablesize
{
	size_t	row;
	size_t	col;
	
}			t_tablesize;

typedef struct s_cellchar
{
	size_t	len;
	char	*posi;
}				t_cellchar;


void		free_sub(char ***ret, size_t i);
void		free_table(char	***table);

int			get_fd(char *argv);
void		err_exit(char *str);
t_tablesize	chk_and_get_datasize(char *arg);
char		***get_data(int fd, t_tablesize tablesize);
size_t		head_space_size(char *str);
int			is_head_dbl(char *str);
int			is_in_dbl(char *str);


#endif
