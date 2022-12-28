#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("hello main\n");
    
    int rc = fork();
    int a = 1;
    int *b;

    b = malloc(5*sizeof(int));
    b[0] = 3;
 
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } 
    else if (rc == 0) {
        b[0] = 5;
        printf("child sees b address is %p and b0 is %d\n", b, b[0]);
        printf("a is %p\nI am child process %d\n", &a, getpid());
    } 
    else {
        sleep(1);
        printf("parent sees b address is %p and b0 is %d\n", b, b[0]);
        printf("a is %p\nI am parent process of (%d), %d\n", &a, rc, getpid());
        exit(0);
    }
    printf("I am child process %d\n", getpid());
    return 0;
}
