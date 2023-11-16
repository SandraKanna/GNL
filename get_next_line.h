/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:44:09 by skanna            #+#    #+#             */
/*   Updated: 2023/11/16 22:56:15 by skanna           ###   ########.fr       */
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

/*typedef struct s_arg
{
	int	i;
	int	j;
}t_arg;
*/


char	*get_next_line(int fd);
void free_all(t_list *lst);
t_list	*ft_lstnew(char *buf, int bytes);
int	check_line(t_list *lst, char c);
char	*join_content(t_list *lst);
char	*ft_strdup(const char *s);

#endif