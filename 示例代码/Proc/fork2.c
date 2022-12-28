#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    printf("hello main\n");
    
    int rc = fork();
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } 
    else if (rc == 0) {
        printf("I am child process %d\n", getpid());
    } 
    else {
        printf("I am parent process of (%d), %d\n", rc, getpid());
    }

    printf("I'm back to main %d\n", getpid());
    return 0;
}
