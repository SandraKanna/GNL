/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:44:09 by skanna            #+#    #+#             */
/*   Updated: 2023/11/15 16:57:00 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
void	add_lst(t_list *lst, t_list *new);
//char	*ft_strchr(char *str, int c);
t_list	*ft_lstnew(char *buf, int read_bytes);
t_list	*ft_lstjoin(t_list *lst);
char 	*read_check_alloc(int fd);
int		ft_lstchr(t_list *lst, char c);

#endif