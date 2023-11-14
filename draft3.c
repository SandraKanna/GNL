#include "get_next_line.h"
#include <stdio.h>

static int	chars_in_line(char *buf, int read_bytes)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && i < read_bytes)
		i++;
	// if (buf[i] != '\n')
	// 	i++;
	return (i);
}

void	add_lst(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		lst = &new;
	else
	{
		last = ft_lstlast(lst);
		last->next = new;	
	}
	return ;
}

int	read_save(int fd, char *buf, t_list **lst, int read_len)
{
	t_list	*new;
	int		line_len;

	new = NULL;
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	read_len = read(fd, buf, BUFFER_SIZE);
	if (read_len <= 0)
		return (0);
	line_len = chars_in_line(buf, read_len);
	if (line_len == read_len)
		new = ft_lstnew(buf, read_len);
	while (line_len < read_len && buf)
	{	
		new = ft_lstnew(buf, line_len);
		add_lst(lst, new);
		buf += line_len;
		read_len -= line_len;
		line_len = chars_in_line(buf, read_len);
		//new = ft_lstnew(buf + line_len, read_len - line_len);
	}
	add_lst(lst, new);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	**lst = NULL;
	t_list			*new_line;
	char			*buffer;
	int				read_len;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	new_line = NULL;
	buffer = NULL;
	read_len = 1;
	while (!lstchr(lst, '\n') && read_len > 0)
	{
		if(!read_save(fd, buffer, lst, read_len))
		{
			free(buffer);
			return (NULL);
		}
		printf("lst->")
		new_line = ft_lstjoin(lst);


	}
	return (new_line->content);
}
