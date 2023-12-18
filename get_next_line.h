#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#define BUFFER_SIZE 512

typedef	struct		s_lst
{
	int				fd;
	char			*heap;
	struct s_lst	*next;
}					t_lst;

int		get_next_line(int fd, char **line);
t_lst	*get_fd(t_lst **list, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strnew(size_t size);
size_t	ft_strlen(const char *s);

#endif

