/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:44:09 by skanna            #+#    #+#             */
/*   Updated: 2023/11/21 19:29:34 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
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
void 	free_all(t_list **lst);
t_list	*ft_lstnew(char *buf, int bytes);
int	check_line(t_list *lst, char c, int read_bytes);
//char	*join_content(t_list **join);
//char	*ft_strdup(const char *s);
//char	*ft_strjoin(char const *s1, char const *s2);
void	check_rest(t_list **lst, int i);

#endif