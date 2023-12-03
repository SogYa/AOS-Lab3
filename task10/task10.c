#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/signal.h>

void action(int sig)
{
    int status;
    printf("Старт сигнала %d\n", sig);
    sleep(5);
    printf("Завершение %d\n", sig);
}

void actionINT(int sig)
{
    int status;
    printf("INT bстарт сигнала %d\n", sig);
    sleep(5);
    printf("INT завершение %d\n", sig);
}

int main(void)
{
    static struct sigaction act, oact, actINT;
    pid_t pid, ch_pid;

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);

    actINT.sa_handler = actionINT;
    actINT.sa_mask = mask;
    actINT.sa_flags = SA_RESTART;
    sigaction(SIGINT, &actINT, &oact);

    act.sa_handler = action;
    act.sa_mask = mask;
    act.sa_flags = SA_RESTART;
    sigaction(SIGCHLD, &act, &oact);

    if (!fork())
    {
        printf("child process %d\n", getpid());
        sleep(1);
        exit(0);
    }
    else
    {
        printf("PARENT process %d\nignore Ctrl+C\n", getpid());

        sleep(5);
        int status;
        wait(&status);
        printf("%x\n", status);
        exit(0);
    }
}