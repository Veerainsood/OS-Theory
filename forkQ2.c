#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;

    // Create a child process
    int a;
    if(fork() && fork()) 
        fork();
    printf("Hello, World!\n");
    return 0;
}
/*
4 times printed fork
Explaination:
    - The first fork() inside the if statement creates a child process which has value 0, so there are two processes now. 
      so the child does not enter the if statement and the parent enters the if statement and creates another child process due to the second fork() statement.
    - Now there are 3 processes, the child process again has 0 value and the parent process has a non-zero value. 
      The parent process enters the if statement and creates another child process due to the third fork() statement.
      this makes 4 processes in total. printing Hello
      
*/