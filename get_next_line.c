/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:06:39 by skanna            #+#    #+#             */
/*   Updated: 2023/11/08 17:15:14 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

char	*get_next_line(int fd)
{
	//read something from fd: size_t read(int fd, void *buf, size_t buff_size);
    //read line up to buff_size OR until the \n char is encountered
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