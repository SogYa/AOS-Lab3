#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <limits.h>

int i;

void child_signal_handler(int sig)
{
    if (sig == SIGALRM)
    {
        printf("Изменили итератор: %d\n", i);

        i = 9000;
    }
    else
        signal(sig, SIG_DFL);
}

void child_code()
{
    //signal(SIGALRM, child_signal_handler);
    alarm(1);
    for (i = 0; i < 10000; i++)
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
        child_code();
    }
    else
    {
        int code;
        sleep(4);
        kill(child_pid, SIGUSR2);
        wait(&code);
        printf("статус завершения:%d\n", code);
    }
    return 0;
}