#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {	
   char *str = argv[1];	

   for(int i=0;i<3;i++) {		
      printf("Hello %s\n", str);		
      //sleep(1);	
   }	
   
   return 0;
}
