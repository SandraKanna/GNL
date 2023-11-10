#include "get_next_line.h"
#include <stdio.h>

static int	chars_in_line(char *buf, int read_bytes)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' && i < read_bytes)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	t_list			*new_line;
	t_list			*last_read;
	char			*buffer;
	int				len_line;
	int				read_bytes;

	// printf("fd read: %i\n", fd);
	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 65535 || fd < 0)
		return (NULL);
	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	len_line = 0;
	new_line = NULL;
	last_read = NULL;
	// while (read_bytes == BUFFER_SIZE)
	while (read_bytes != 0)
	// while (*buffer != '\0')
	{
		if (!ft_strchr (buffer, '\n'))
			new_line = ft_lstnew(buffer, read_bytes);
		else
		{
			// strjoin???
			len_line = chars_in_line(buffer, read_bytes);
			new_line = ft_lstnew(buffer, len_line);
		}
		if (lst == NULL)
			lst = new_line;
		else
		{
			last_read = ft_lstlast(lst);
			last_read->next = new_line;
		}
		//lstmap avec strjoin

		return (new_line->content);
	}
	return (new_line->content);
}
