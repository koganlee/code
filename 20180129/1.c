#include "apue.h"
void *thread_function(void* num);
int main()
{
   pthread_t a_thread;
   void *thread_result;
   int num = 1;
   int res;

   res =  pthread_create(&a_thread, NULL, thread_function, &num ); 
   if(res != 0) {
	   perror("Thread creation failed\n");
	   exit(EXIT_FAILURE);
   }
   printf("Waiting for thread to finish...\n");
   res = pthread_join(a_thread, &thread_result);
   if(res != 0) {
	   perror("Thread join failed");
	   exit(EXIT_FAILURE);
   }

   printf("Thread joined, it return %d\n",*(int *)thread_result);
   printf("Num is now %d\n",*(int*) thread_result);

     exit(EXIT_SUCCESS);
}


void *thread_function(void *num)
{
   printf("num = %d\n", *(int *)num);
 
   *(int *) num = 2;
}
