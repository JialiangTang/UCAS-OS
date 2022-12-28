#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int counter = 0;
int loops;
pthread_mutex_t mutex;

void *worker(void *arg) {	
   pthread_mutex_lock(&mutex);
   for (int i=0;i<loops;i++) {
      counter++;
   }
   pthread_mutex_unlock(&mutex);
   sleep(10);	
   return NULL;
}

int main(int argc, char *argv[]) { 
   struct timespec start, finish;
   loops = atoi(argv[1]);
   printf("Initial value: %d\n", counter);	
   pthread_mutex_init(&mutex, 0);
   
   clock_gettime(CLOCK_MONOTONIC, &start);
   pthread_t p1, p2;

   pthread_create(&p1, NULL, worker,NULL);
   pthread_create(&p2, NULL, worker,NULL);

   pthread_join(p1, NULL);
   pthread_join(p2, NULL);
   
   pthread_mutex_destroy(&mutex);
   printf("Final value: %d\n", counter);

   clock_gettime(CLOCK_MONOTONIC, &finish);
   unsigned long long value = (finish.tv_sec - start.tv_sec) *1000000000 + finish.tv_nsec - start.tv_nsec;

   printf("elasped time is %lld ns\n", value);  
   return 0;
}

