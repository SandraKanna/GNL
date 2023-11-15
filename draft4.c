#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

typedef struct s_list {
    char *content;
    struct s_list *next;
} t_list;

static t_list *g_save = NULL;

static void add_lst(t_list **lst, t_list *new) {
    if (!*lst)
        *lst = new;
    else {
        t_list *last = *lst;
        while (last->next)
            last = last->next;
        last->next = new;
    }
}

static t_list *ft_lstnew(char *buf, int bytes) {
    t_list *new_node = malloc(sizeof(t_list));
    if (!new_node)
        return NULL;

    new_node->content = malloc(sizeof(char) * (bytes + 1));
    if (!new_node->content) {
        free(new_node);
        return NULL;
    }

    memcpy(new_node->content, buf, bytes);
    new_node->content[bytes] = '\0'; // Null-terminate the string
    new_node->next = NULL;

    return new_node;
}

static void free_lst(t_list *lst) {
    while (lst) {
        t_list *temp = lst;
        lst = lst->next;
        free(temp->content);
        free(temp);
    }
}

static char *ft_alloc_lsts(int fd) {
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    t_list *new = NULL;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer
        new = ft_lstnew(buffer, bytes_read);
        if (!new) {
            free_lst(g_save);
            return NULL;
        }
        add_lst(&g_save, new);

        char *newline = strchr(buffer, '\n');
        if (newline) {
            *newline = '\0'; // Null-terminate at newline
            break;
        }
    }

    if (g_save) {
        char *line = strdup(g_save->content);
        t_list *temp = g_save;
        g_save = g_save->next;
        free(temp->content);
        free(temp);
        return line;
    }

    return NULL;
}

char *get_next_line(int fd) {
    char *line = ft_alloc_lsts(fd);
    if (line)
        return line;
    else
        free_lst(g_save);
    return NULL;
}

int	main (void)
{
	int	fd = open("test", O_RDONLY);
	int i = 6;
	char *line;
	// const char *str = "youhuuuu \n ca va bien blabla	!wow. Yep\n no";

	//while ((line = get_next_line(fd)) != NULL)
	while(i > 0)
	{	
		line = get_next_line(fd);
		printf("Line: %s\n", line);
		free(line);
		i--;
	}
	close(fd);
	return (0);
}
