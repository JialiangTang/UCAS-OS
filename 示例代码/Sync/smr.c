#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 1024

int main(int args, char *argv[]) {
    int shmid;
    int ret;
    key_t key;
    char *shmadd;

    if ((key = ftok("./", 2021)) == -1) {
        perror("ftok error.");
    }

    printf("start-ipcs------------------------------------------\n");
    system("ipcs -m");
    printf("end-ipcs--------------------------------------------\n");

    if ((shmid = shmget(key, BUFFSIZE, IPC_CREAT|0666)) < 0) {
        perror("shmget error.");
        exit(-1);
    }
    printf("Open shared-memory success, with shmid: %d\n", shmid);


    if ((shmadd = (char *)shmat(shmid, NULL, 0)) < 0) {
        perror("shmat error.");
        exit(-1);
    }

    printf("read data from shared-memory\n");
    printf("%s\n", shmadd);

    if ((ret = shmdt(shmadd)) < 0) {
        perror("shmdt error.");
        exit(1);
    } 
    else {
        printf("Delete shared-memory\n");
    }

    shmctl(shmid, IPC_RMID, NULL);

    printf("start-ipcs------------------------------------------\n");
    system("ipcs -m");
    printf("end-ipcs--------------------------------------------\n");

    return 0;
}
