#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1, fd2;
    char *line1;
    char *line2;

    // ------------------------- //
    //   Open files for testing  //
    // ------------------------- //
    fd1 = open("text1.txt", O_RDONLY);
    fd2 = open("text2.txt", O_RDONLY);
    if (fd1 < 0 || fd2 < 0)
    {
        printf("Error opening files.\n");
        return (1);
    }

    // ------------------------- //
    //   TEST SINGLE FD GNL      //
    // ------------------------- //
    printf("---- Testing get_next_line(fd1) ----\n");
    while ((line1 = get_next_line(fd1)) != NULL)
    {
        printf("FD1: %s", line1);
        free(line1);
    }
    close(fd1); // Close after single FD test

    // ------------------------- //
    //   TEST MULTIPLE FD BONUS  //
    // ------------------------- //
    // Reopen FD1 to start from beginning
    fd1 = open("text1.txt", O_RDONLY);
    if (fd1 < 0)
    {
        printf("Error reopening fd1.\n");
        close(fd2);
        return (1);
    }

    printf("\n---- Testing get_next_line_bonus(fd1 & fd2) ----\n");
    while (1)
    {
        line1 = get_next_line_bonus(fd1);
        line2 = get_next_line_bonus(fd2);

        if (!line1 && !line2)
            break;

        if (line1)
        {
            printf("FD1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("FD2: %s", line2);
            free(line2);
        }
    }

    close(fd1);
    close(fd2);
    return 0;
}
