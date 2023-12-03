#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

void cycle()
{
    pause();
    exit(0);
}

int main()
{

    int child_pid = fork();

    if (!child_pid)
    {
        cycle();
    }
    else
    {
        int code;
        sleep(1);
        kill(child_pid, SIGUSR2);
        wait(&code);
        printf("статус завершения:%d\n", code);
    
    }
    return 0;
}