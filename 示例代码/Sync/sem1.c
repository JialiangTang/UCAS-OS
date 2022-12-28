#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

int counter = 0;
int loops;
pthread_mutex_t mutex;
sem_t f1, f2;

void *worker1(void *arg) {	
   int i = 0;
   for (i=0;i<loops;i++) {
      sem_wait(&f1);
      counter++;
      sem_post(&f2);
      printf("worker 1 counter: %d\n", counter);
   }	
   return NULL;
}

void *worker2(void *arg) {	
   int i = 0;
   for (i=0;i<loops;i++) {
      sem_wait(&f2);
      counter--;
      sem_post(&f1);
      printf("worker 2 counter: %d\n", counter);
   }	
   return NULL;
}

int main(int argc, char *argv[]) { 
   struct timespec start, finish;
   loops = atoi(argv[1]);
   printf("Initial value: %d\n", counter);	
   sem_init(&f1, 0, 1);
   sem_init(&f2, 0, 0);  
   //clock_gettime(CLOCK_MONOTONIC, &start);
   pthread_t p1, p2;

   pthread_create(&p1, NULL, worker1,NULL);
   pthread_create(&p2, NULL, worker2,NULL);

   pthread_join(p1, NULL);
   pthread_join(p2, NULL);
   
   pthread_mutex_destroy(&mutex);
   printf("Final value: %d\n", counter);

   //clock_gettime(CLOCK_MONOTONIC, &finish);
   //unsigned long long value = (finish.tv_sec - start.tv_sec) *1000000000 + finish.tv_nsec - start.tv_nsec;

   //printf("elasped time is %lld ns\n", value);  
   return 0;
}

