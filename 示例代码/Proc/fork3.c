#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("hello main\n");
    
    int rc = fork();
    int a = 3;
    
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
    } 
    else if (rc == 0) {
        printf("a is %d\nI am child process %d\n", a,getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");  
        myargs[1] = strdup("fork3.c"); 
        myargs[2] = NULL;           
        execvp(myargs[0], myargs); 
        printf("after execvp a is %d\n", a); 
        printf("this should not print out\n");
    } 
    else {
        printf("I am parent process of (%d), %d\n", rc, getpid());
    }

    printf("I'm back to main %d\n", getpid());
    return 0;
}
