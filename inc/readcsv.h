#ifndef READCSV_H
# define READCSV_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <ctype.h>
# include <stdint.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"
# include <errno.h>
# include <readline/readline.h>

# define MAX_CHAR 100

typedef enum	e_type
{
	NONE,
	CHAR,
	INT,
	DBL
}				t_type;

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

typedef union	u_value 
{
	char    *str_val;
	int64_t	int_val;
	double  dbl_val;
}           u_value;

typedef struct	s_table
{
	u_value	value;
	bool	is_quoted;
	bool	is_nil;

}				t_table;

typedef struct	s_CSVdata
{
	int			fd;
	char		*filename;
	char		(*cell_tmp)[MAX_CHAR];
	t_table		**table;
	t_tablesize	tbl_size;
	t_type		*value_type;
	char		separator;
	bool		is_header;
}				t_CSVdata;

// typedef	struct	s_readcsv
// {
// 	char		*name;
// 	char		*filepath;
// 	t_CSVdata	csv_data;
// 	t_readcsv	*next;
// 	t_readcsv	*prev;
	
// }				t_readcsv;



void		free_table(char	***table);
void		print_table(char ***table);
int			get_fd(char *argv);
void		err_exit(char *str);
int			chk_and_get_tablesize(t_tablesize *tbl_size, int fd);
t_table		**get_data(int fd, t_tablesize tbl_size);
size_t		head_space_size(char *str);
int			is_head_dbl(char *str);
int			is_blank(char *str);

// utils
void		skip_blank(char **line);
char		*ft_strtrim(char const *s1, char const *set);
void	csv_split(char const *str, t_CSVdata *csv_data);
void		free_split(char **ret, size_t i);

void		get_datatype(int fd, t_CSVdata *csv_data);

// datatype
bool		is_integer(const char *str);
bool		is_char(const char *str);
bool		is_float(const char *str);


#endif
