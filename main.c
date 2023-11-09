#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main (void)
{
	int	fd;
	int i = 5;
	// const char *str = "youhuuuu \n ca va bien blabla	!wow. Yep\n no";
	// fd = open (str, O_RDONLY);
	fd = open("test", O_RDONLY);
	while(i > 0)
	{	
		get_next_line(fd);
		i--;
	}
	close(fd);
}

/*
Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time

Make sure that your function works as expected both when reading a file and when
reading from the standard input. --> test with different fds (incl fd = 0)

Ex to compile (incl buff_size):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

*/