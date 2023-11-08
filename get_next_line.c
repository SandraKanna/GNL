/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:06:39 by skanna            #+#    #+#             */
/*   Updated: 2023/11/08 20:34:55 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	int				read_bytes; //actual read bytes when calling read
	static t_list	**lst; //text to stock
	t_list			*read_line;
	t_list			*last_read;
	//static	var;

	//protections:
	if (BUFFER_SIZE <= 0)
		return (0);
	if (BUFFER_SIZE > (65535 - 1))
		return (NULL);
	read_bytes = 1;
	//buf malloc?
	buf[BUFFER_SIZE] = '\0';
	*lst = NULL;
	//read line up to buff_size OR until the \n char is encountered
	while (!ft_strchr(buf, '\n') && read_bytes != 0)
	{
	//read the line and store the actual number of read bytes to then malloc the *content
		read_bytes = read(fd, buf, BUFFER_SIZE);
		//store the data/chars/string read
		read_line = ft_lstnew(buf, read_bytes);
		if (*lst == NULL)
			*lst = read_line;
		else
		{
			last_read = ft_lstlast(*lst);
			last_read->next = read_line;
		}
	}
	//print/write data stored

	return (read_line->content);
}

/*
return: the line that was read (incl \n unless end of file reached and it does not end with a \n)
		or NULL if error or nothing else to read

undef behaviour: 
- if the file pointed to by the file descriptor changed since the last call
- when reading a binary file

BONUS:
- use ONLY ONE static variable
- manage multiple file descriptors at the same time

*/