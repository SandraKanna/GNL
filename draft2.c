#include "get_next_line.h"
#include <stdio.h>

static int	chars_in_line(char *buf, int read_bytes)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && i < read_bytes)
		i++;
	if (buf[i] == '\n')
		i++;
	return (i);
}

void	add_lst(t_list *lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL)
		lst = new;
	else
	{
		last = ft_lstlast(lst);
		last->next = new;	
	}
	printf("new: %s\n", new->content);
	printf("lst: %s\n", lst->content);
	return ;
}

void	ft_alloc_lsts(int fd, char *buffer, t_list *lst)
{
	int		bytes_read;
	t_list	*new;
	int		len_new;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		len_new = chars_in_line(buffer, bytes_read);
		new = ft_lstnew(buffer, len_new);
		add_lst(lst, new);
		// printf("2: %s\n", lst->content);
	}
	return ;
}


char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;
	char			*buffer;
	// int				bytes_read;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer [BUFFER_SIZE] = '\0';
	ft_alloc_lsts(fd, buffer, lst);
	printf("1: %s\n", lst->content);
	line = ft_lstjoin(lst);
	
	return (line);
}


