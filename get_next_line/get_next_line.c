/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:17:59 by wrikuto           #+#    #+#             */
/*   Updated: 2023/10/14 23:34:07 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static int	ft_is_newline(char	*buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (0);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

static char	*ft_rtn_line(char	*buf)
{
	char	*rtn_line;
	int		count;
	int		asg;

	count = 0;
	asg = 0;
	if (buf[count] == 0)
		return (NULL);
	while (buf[count] != '\0' && buf[count] != '\n')
		count++;
	rtn_line = malloc(sizeof(char) * (count + ft_is_newline(buf) + 1));
	if (rtn_line == NULL)
		return (NULL);
	while (buf[asg] != '\0' && buf[asg] != '\n')
	{
		rtn_line[asg] = buf[asg];
		asg++;
	}
	if (buf[asg] == '\n')
		rtn_line[asg++] = '\n';
	rtn_line[asg] = '\0';
	return (rtn_line);
}

static char	*ft_to_nextline(char	*buf)
{
	char	*new_buf;
	int		count;
	int		asg;

	count = 0;
	while (buf[count] != 0 && buf[count] != '\n')
		count++;
	if (buf == NULL || buf[count] == 0)
	{
		free (buf);
		return (NULL);
	}
	new_buf = malloc(sizeof(char) * (ft_strlen(buf) - count + 1));
	if (new_buf == NULL)
		return (NULL);
	count++;
	asg = 0;
	while (buf[count] != '\0')
		new_buf[asg++] = buf[count++];
	new_buf[asg] = '\0';
	free(buf);
	return (new_buf);
}

static	char	*ft_read_and_concatenate(int fd, char *buf)
{
	char	*read_buf;
	int		read_byte;

	read_byte = 1;
	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buf == NULL)
		return (NULL);
	while (ft_is_newline(buf) != 1 && read_byte != 0)
	{
		read_byte = read(fd, read_buf, BUFFER_SIZE);
		if (read_byte < 0)
		{
			free(buf);
			free(read_buf);
			return (NULL);
		}
		read_buf[read_byte] = '\0';
		buf = gnl_strjoin(buf, read_buf);
	}
	free(read_buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*rtn_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX || fd > OPEN_MAX)
		return (0);
	buf = ft_read_and_concatenate(fd, buf);
	if (buf == NULL)
		return (NULL);
	rtn_line = ft_rtn_line(buf);
	buf = ft_to_nextline(buf);
	return (rtn_line);
}
