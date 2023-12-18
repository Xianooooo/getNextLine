#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_lst	*get_fd(t_lst **list, int fd)
{
	t_lst	*ret;

	ret = *list;
	while (ret)
	{
		if (ret->fd == fd)
			return (ret);
		ret = ret->next;
	}
	if (!(ret = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	ret->fd = fd;
	ret->heap = NULL;
	ret->next = NULL;
	if (*list == NULL)
		*list = ret;
	else
	{
		ret->next = *list;
		*list = ret;
    }
	return (*list);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[i + s1_len] = s2[i];
	str[i + s1_len] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
    char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	if (!(a = (char*)malloc(sizeof(*a) * (size + 1))))
		return (NULL);
	a[size] = '\0';
	i = 0;
	while (i < size)
		a[i++] = 0;
	return (a);
}

