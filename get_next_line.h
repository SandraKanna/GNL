/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:44:09 by skanna            #+#    #+#             */
/*   Updated: 2023/11/14 13:00:01 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
t_list	*ft_lstnew(char *buf, int read_bytes);
t_list	*ft_lstlast(t_list **lst);
t_list	*ft_lstjoin(t_list **lst);
int	lstchr(t_list **lst, int c);

#endif