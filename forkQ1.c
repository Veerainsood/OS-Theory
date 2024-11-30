#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;

    // Create a child process
    int a;
    for(int i=1;i<5;i++)
    {
        fork();
    }
    printf("Hello, World!\n");
    return 0;
}
/*
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
Hello, World!
*/