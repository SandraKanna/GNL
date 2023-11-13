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
	//t_list			*new_line;
	char			*buffer;
    char            *temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
    len_line = 0;
	new_line = NULL;
	last_read = NULL;
	while (!ft_strchr(lst->content, '\n' && read_bytes > 0))
    {
        buffer = malloc (BUFFER_SIZE + 1);
	    if (!buffer)
		    return (NULL);
	    read_bytes = read(fd, buffer, BUFFER_SIZE);
	    buffer[read_bytes] = '\0';

    }
	return (get_line);
}
