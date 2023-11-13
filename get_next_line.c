/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:06:39 by skanna            #+#    #+#             */
/*   Updated: 2023/11/13 14:33:36 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	t_list			*new_line;
	char			*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	read_bytes = 1;
	new_line = NULL;
	while (!ft_strchr(buffer, '\n') && read_bytes != 0)
	{
		ft_alloc(fd, buffer, lst);
		
	}

	return (new_line->content);
}

void	ft_alloc(int fd, char *buff, t_list *lst)
{
		int		read_bytes;
		t_list	*element_in_lst;
		t_list	*last_read;
		
		buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (NULL);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		element_in_lst = ft_lstnew(buff, read_bytes);
		if (&lst == NULL)
			lst = element_in_lst;
		else
		{
			last_read = ft_lstlast(lst);
			last_read->next = element_in_lst;
		}
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