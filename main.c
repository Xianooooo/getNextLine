#include "get_next_line.h"
#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    char    *line;

    while (get_next_line(0, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    return (0);
}
