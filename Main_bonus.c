#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

void test_gnl(const char *filename, int fd)
{
    char *line;
    int line_count = 0;

    printf("Testing file: %s (fd: %d)\n", filename, fd);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", ++line_count, line);
        free(line);
    }
    printf("\nEnd of file reached. Total lines: %d\n\n", line_count);
}

int main()
{
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    int fd3 = open("test3.txt", O_RDONLY);

    test_gnl("test1.txt", fd1);
    test_gnl("test2.txt", fd2);
    test_gnl("test3.txt", fd3);
}
