#include "apue.h"

typedef struct{
   pthread_cond_t cond;
   pthread_mutex_t mutex;
}mark;

void *pthread_function(void * ptr);

int main()
{
   pthread_t a_thread;
   int res;
   mark flag;

   res = pthread_cond_init(&flag.cond, NULL);
   if(res != 0 ) {
	   printf("cond failure. num=%d\n", res);
	   return -1;
   }

   pthread_mutex_init(&flag.mutex, NULL);
   pthread_create(&a_thread, NULL, pthread_function, &flag);
    
   sleep(4);
   pthread_cond_signal(&flag.cond);
   pthread_join(a_thread, NULL);
   printf("End\n");
   return 0;

}

void *pthread_function(void *ptr)
{
    mark *data = (mark *)ptr;
    
    int res;
	printf("I am thread1\n");
    pthread_mutex_lock(&data -> mutex);
	res = pthread_cond_wait(&data-> cond, &data -> mutex);
	pthread_mutex_unlock(&data -> mutex);
	printf("wake up, res = %d\n", res);
	pthread_exit(NULL);
}




