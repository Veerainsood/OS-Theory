#include <unistd.h>
#include <stdio.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        printf("%d\n",getpid());
        execl("/bin/ls", "ls", "-l", (char *)NULL);
        // If execl returns, there was an error
        perror("exec failed");
    } else if (pid > 0) {
        // Parent process
        printf("Parent process %d, child PID: %d\n", getpid(),pid);
    } else {
        // Fork failed
        perror("fork failed");
    }

    return 0;
}
