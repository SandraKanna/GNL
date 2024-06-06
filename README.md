# Get next line 42
The GNL project from 42 School requires to write a function that reads the content of a given file descriptor (fd) and returns it line by line.
The main goal is to learn about static variables (a type of variable that maintains its value between function calls).

This interesting project also helped me learn how to use **linked lists**, get more comfortable with **pointers** and understand a little better **file descriptors** and **global variables**.

### Passed the moulinette with 125
The mandatory function already takes into account the bonus part (handling multiple fds and using only one static variable), so the files marked with "bonus" are just a copy so the bonus part could be graded by the moulinette. 

The way it handles multiple fds is by creating a table of linked lists. That is wo say, I create one linked list everytime I get a different fd as parameter.
