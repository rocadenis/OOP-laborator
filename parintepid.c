#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i, j;
    pid_t pid;

    printf("(1,1) PID=%d ParentPID=%d\n", getpid(), getppid());

    for (i = 1; i <= 5; i++) {
        pid = fork();
        if (pid == 0) {
            printf("(%d,%d) PID=%d ParentPID=%d\n", 2, i, getpid(), getppid());
            for (j = 1; j <= 10; j++) {
                pid = fork();
                if (pid == 0) {
                    printf("(%d,%d) PID=%d ParentPID=%d\n", 3, (i-1)*2+j, getpid(), getppid());
                    return 0;
                }
            }
            for (j = 1; j <= 10; j++) {
                wait(NULL);
            }
            return 0;
        }
    }

    for (i = 1; i <= 5; i++) {
        wait(NULL);
    }

    return 0;
}
