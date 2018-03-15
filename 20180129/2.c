#include "apue.h"
void cleanup(void *ptr)
{
    free(ptr);
	printf("memory\n");

}
void* thread_function(void *ptr)
{
   ptr = malloc(4);
   pthread_cleanup_push(cleanup, (void *) ptr);
   printf("end\n");
   read(0,ptr ,1);
   pthread_cleanup_pop(1);
}



//main线程最后退出
int main()
{
	pthread_t a_pthread;

			int res;
		
			res=pthread_create(&a_pthread,NULL,thread_function,NULL);
			if(res!=0)	{		
			   printf("pthread_create ret=%d\n",res);
			   return -1;					
			}
			pthread_cancel(a_pthread);
			pthread_join(a_pthread,NULL);
		    printf("I am main thread\n");
			return 0;
}
