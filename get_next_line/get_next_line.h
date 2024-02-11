/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:28:55 by wrikuto           #+#    #+#             */
/*   Updated: 2024/02/12 00:55:51 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>
# include<fcntl.h>
# include<limits.h>
# include<stdbool.h>
# include<errno.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef GNL_RESET
#  define GNL_RESET 1
# endif 

# ifndef GNL_CONSUME
#  define GNL_CONSUME 0
# endif 


size_t	ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd, bool flag_reset);

#endif