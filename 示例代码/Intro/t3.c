#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {	
      int *array = malloc(5*sizeof(int));	
      printf("The starting address of the in-memory array is %p\n", array);	
      array[0] = 1;	
      for(int i=1;i<5;i++) {	
         array[i] = array[i-1] + i;		   
         printf("The %d element is %d\n", i, array[i]);	
      }	

      return 0;
}
