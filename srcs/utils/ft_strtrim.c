
#include "../../inc/readcsv.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	new_len;
	char	*new;

	new_len = 1;
	if (start < ft_strlen(s))
		new_len = ft_strlen(s) - start + 1;
	if (new_len > len)
		new_len = len + 1;
	new = malloc(new_len);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s + start, new_len - 1);
	new[new_len - 1] = '\0';
	return (new);
}


static const char	*find_head(char const *s, char const *set)
{
	char const	*head;

	head = s;
	while (strchr(set, *head))
		head++;
	return (head);
}

static const char	*find_tail(char const *s, char const *set)
{
	char const	*tail;

	tail = NULL;
	while (*s)
	{
		if (strchr(set, *s) == NULL)
			tail = s;
		s++;
	}
	return (tail);
}

// s1: not protected
// set: not protected
char	*ft_strtrim(char const *s1, char const *set)
{
	const char		*head;
	const char		*tail;
	unsigned int	start;
	size_t			len;

	head = find_head(s1, set);
	tail = find_tail(s1, set);
	if (tail < head)
		return (strdup(""));
	start = (unsigned int)(head - s1);
	len = (size_t)(tail - head + 1);
	return (ft_substr(s1, start, len));
}
