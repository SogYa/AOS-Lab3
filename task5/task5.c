#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

void cycle()
{
    for (int i = 0; i < 1000; i++)
    {
        printf("Номер итерации: %d\n", i);
        for (int j = 0; j < 1000; j++)
            for (int k = 0; k < 1000; k++)
                NULL;
    }
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
        kill(child_pid, SIGUSR1);
        wait(&code);
        printf("статус завершения:%d\n", code);
    }
    return 0;
}