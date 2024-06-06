# Get next line 42
The GNL project from 42 School requires to write a function that reads the content of a given file descriptor (fd) and returns it line by line.
The main goal is to learn about static variables (a type of variable that maintains its value between function calls).

This interesting project also helped me learn how to use **linked lists**, become more comfortable with **pointers** and better understand **file descriptors** and **global variables**.

Regarding linked lists: Each node of the list contains a char** with the strings read into the buffer. 
Every time a node is created, I check for “\n” and EOF so I can return a line. 
Once a line is returned, the nodes are freed, but not before checking for any remaining content stored in the subsequent nodes.

### Passed the moulinette with 125
The mandatory function already takes into account the bonus part (handling multiple fds and using only one static variable), so the files marked with "bonus" are just a copy so the bonus part could be graded by the moulinette. 

The way it handles multiple fds is by creating a table of linked lists: I create one linked list everytime I get a different fd as parameter.
