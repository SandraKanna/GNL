#include "get_next_line.h"

static int	chars_to_cpy(char *buf, int BUFFER_SIZE)
{
	int	i;

	i = 0;
	while (buf[i] != '\n' || i < BUFFER_SIZE)
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	t_list			*line;
	static t_list	*all_text;
	t_list			*last_read;
	char			*buffer;
	int				len_line;
	size_t			read_bytes;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > 65535 || fd < 0)
		return (NULL);
	buffer[BUFFER_SIZE + 1];
	buffer[BUFFER_SIZE] = '\0';
	read_bytes = 1;
	len_line = 0;
	line = NULL;
	all_text = NULL;
	// while (len_line == BUFFER_SIZE)
	while (read_bytes != 0)
	{
		read_bytes = read (fd, buffer, BUFFER_SIZE);
		if (!ft_strchr (buffer, '\n'))
		{
			line = ft_lstnew(buffer, read_bytes);
			if (all_text == NULL)
				all_text = line;
			else
			{
				last_read = ft_lstlast(all_text);
				last_read->next = line;
			}
		}
		else
		{
			while ()
			{
				len_line = chars_to_cpy(buffer, BUFFER_SIZE);


		}
		
	}
	return (line->content);

}
