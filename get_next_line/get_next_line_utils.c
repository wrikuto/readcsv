/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:38:15 by wrikuto           #+#    #+#             */
/*   Updated: 2023/08/09 12:54:17 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

static char	*if_s1_null(char *s1)
{
	s1 = malloc(sizeof(char));
	s1[0] = '\0';
	return (s1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = -1;
	j = 0;
	if (s1 == NULL)
		s1 = if_s1_null(s1);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}
