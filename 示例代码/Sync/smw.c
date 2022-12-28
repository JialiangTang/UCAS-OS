#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
    int shmid;
    key_t key;
    char *shmadd;
    char *msg;


    if ((key = ftok("./", 2021)) == -1) {
        perror("ftok error");
    }

    if ((shmid = shmget(key, BUFFSIZE, IPC_CREAT|0666)) < 0) {
        perror("shmget error.");
        exit(-1);
    }
    printf("Create shared-memory success, with shmid: %d\n", shmid);


    if ((shmadd = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat error.");
        exit(-1);
    }

    printf("copy data to shared-memory\n");
    bzero(shmadd, BUFFSIZE);
    msg = "hello, shared memory";
    strcpy(shmadd, msg);
    printf("copy data to shared-memory success, with msg: %s\n", msg);
}
