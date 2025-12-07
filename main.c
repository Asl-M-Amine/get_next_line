#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("text1.txt", O_RDONLY);
    int fd2 = open("text2.txt", O_RDONLY);
    int fd3 = open("text3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("open");
        return 1;
    }

    char *line1 = NULL;
    char *line2 = NULL;
    char *line3 = NULL;

    while (1)
    {
        int all_eof = 1; // check if all files are done

        if ((line1 = get_next_line_bonus(fd1)))
        {
            printf("FD1 : %s", line1);
            free(line1);
            all_eof = 0;
        }

        if ((line2 = get_next_line_bonus(fd2)))
        {
            printf("FD2 : %s", line2);
            free(line2);
            all_eof = 0;
        }

        if ((line3 = get_next_line_bonus(fd3)))
        {
            printf("FD3 : %s", line3);
            free(line3);
            all_eof = 0;
        }

        if (all_eof)
            break; // stop when all files are finished
    }

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
