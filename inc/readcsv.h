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

# define RD_SIZE 100

typedef enum	e_type
{
	CHAR,
	INT,
	DBL,
	NONE
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
	int     int_val;
	double  dbl_val;
}           u_value;

typedef struct	s_table
{
	u_value	value;
	bool	is_quoted;

}				t_table;



typedef struct	s_CSVdata
{
	t_table		**table;
	t_tablesize	tbl_size;
	t_type		*value_type;
	bool		is_header;
}				t_CSVdata;


void		free_table(char	***table);
void		print_table(char ***table);
int			get_fd(char *argv);
void		err_exit(char *str);
t_tablesize	chk_and_get_datasize(char *arg);
t_table	**get_data(int fd, t_tablesize tbl_size);
size_t		head_space_size(char *str);
int			is_head_dbl(char *str);
int			is_blank(char *str);

// utils
void	skip_blank(char **line);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
t_type	*get_datatype(char *line, t_tablesize tbl_size);

// datatype
bool	is_integer(const char *str);
bool	is_char(const char *str);
bool	is_float(const char *str)


#endif
