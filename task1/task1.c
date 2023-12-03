#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

void disp(int param)
{
    printf("SIGINT\n");
    signal(param, SIG_DFL);
    printf("SIGDF\n");
}

int main()
{
    signal(SIGINT, disp);

    while (1)
        sleep(1);

    return 0;
}