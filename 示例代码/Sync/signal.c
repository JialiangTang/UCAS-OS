#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sigproc()
{ 		
   signal(SIGINT, sigproc);
   printf("you have pressed ctrl-c - disabled");
}

void quitproc()
{ 		 
   printf("ctrl-\\ pressed to quit\n");
   exit(0);
}

int main()
{ 
   signal(SIGINT, sigproc);  
   signal(SIGQUIT, quitproc); 
   printf("ctrl-c disabled use ctrl-\\ to quit\n");
  
   for(;;);
   exit(0);  
}

