

#include <pthread.h>
#include <sched.h>


#define THREAD_NUMBERS 12
void start_rw_test(int bind_cpu){
    cpu_set_t cpuset;
    CPU_ZERO(&cpu_set);
    CPU_SET(bind_cpu, &cpuset);
    sched_setaffinity(0, sizeof(cpuset), &cpuset);
}

/******************** pthread_create *******************/
int main(){
    pthread_t pthread[THREAD_NUMBERS];

    for(int i = 0; i < THREAD_NUMBERS; ++i){
        // i is the argument of start_rw_test
        pthread_create(&pthread[i], NULL, (void *)start_rw_test, i);
    }
}



/********************** fork ****************************/

int main(){
    for(int i = 1; i < THREAD_NUMBERS; ++i){
        pid_t p = fork();
        if(p < 0){
            printf(" fork error\n");
        }
        else if(!p){
            start_rw_test(i);
            exit(0);
        }
    }
    start_rw_test(0);
    wait;
}

