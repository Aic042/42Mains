#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
 {
    int fd = open("test.txt", O_RDONLY);
   char *line;
    while ((line = get_next_line(fd)))
    {
     printf("%s\n", line);
     free(line);
    }
    close(fd);
    free(line);
  return (0);  
 }
