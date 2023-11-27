#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

int	main (void)
{
	int	fd;
	int i = 1;
	char *line;

	fd = open("giant_line.txt", O_RDWR);
	//while ((line = get_next_line(fd)) != NULL)
	while(i > 0)
	{	
		line = get_next_line(fd);
		printf("Line: %s\n", line);
		free(line);
		i--;
	}
	close(fd);
	// line = get_next_line(fd);
	// printf("Line: %s\n", line);
	// free(line);
	return (0);
}
