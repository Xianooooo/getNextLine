# getNextLine

## int	get_next_line(int fd, char **line)

A function that written in c which allows you to read the next line from files or standard input
function

int fd: file descriptor of the file that is be read.

char **line: pointer to heap allocated memory which stores the line that being read from the file.

return(0) successful read, return (-1) failed read.

test with main.c which reads from standard input

compile: gcc get_next_line.c get_next_line_utils.c main.c -I . 
