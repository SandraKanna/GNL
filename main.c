int	main (void)
{
	fd == ??
	//while: tant qu'il y a encore des lignes a lire --> get_next_line(fd)
}

/*
Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time

Make sure that your function works as expected both when reading a file and when
reading from the standard input. --> test with different fds (incl fd = 0)

Ex to compile (incl buff_size):
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

*/