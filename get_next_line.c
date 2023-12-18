#include "get_next_line.h"

static int	find_newline(char *stack)
{
	size_t	i;

	i = -1;
	while (stack[++i])
		if (stack[i] == '\n')
			return (1);
	return (0);
}

static int	get_line(t_lst *current, char **line)
{
	size_t	i;
	size_t	j;
	char	*new;

	j = -1;
	i = 0;
	while (current->heap[i] != '\n' && current->heap[i] != '\0')
		i++;
	if (current->heap[i] == '\n')
	{
		*line = ft_strnew(i);
		while (++j < i)
			(*line)[j] = current->heap[j];
		new = ft_strdup(current->heap + i + 1);
		free(current->heap);
		current->heap = new;
	}
	else if (current->heap[i] == '\0')
	{
		*line = ft_strdup(current->heap);
		free(current->heap);
		current->heap = NULL;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				ret;
	char			*new;
	static t_lst	*lst;
	t_lst			*current;
	char			stack[BUFFER_SIZE + 1];

	if (fd < 0 || !(current = get_fd(&lst, fd)))
		return (-1);
	while ((ret = read(fd, stack, BUFFER_SIZE)) > 0)
	{
		current->heap = (current->heap == NULL) ? ft_strnew(0) : current->heap;
		stack[ret] = '\0';
		new = ft_strjoin(current->heap, stack);
		free(current->heap);
		current->heap = new;
		if (find_newline(stack))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (current->heap == NULL || current->heap[0] == '\0'))
		return (0);
	return (get_line(current, line));
}
