#define _XOPEN_SOURCE 700
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
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = disp;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    while(1)
        sleep(1);
    return 0;
}