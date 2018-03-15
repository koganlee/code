#include "apue.h"
struct mu{
   pthread_mutex_t mark;
   long num;
};
#define N 50000000
void *pthread_function(void *f);
int main()
{
	struct mu  flag;
    pthread_t a_thread;
    pthread_mutex_init(&flag.mark, NULL);
    flag.num = 0;

    int res = pthread_create(&a_thread, NULL, pthread_function,(void*)&flag);
	if(res != 0) {
		printf("thread creation failed\n");
		return -1;
	}
    int n = 0;
     for(n = 0; n < N; n++)
	 {
		  pthread_mutex_lock(&flag.mark);
          flag.num += 1;
          pthread_mutex_unlock(&flag.mark);
	 }
  	 pthread_join(a_thread, NULL);
     printf("num = %ld\n", flag.num);
     pthread_mutex_destroy(&flag.mark);
	 pthread_exit(&a_thread);
    return 0;
}



void *pthread_function(void *f)
{   
    struct mu *temp = (struct mu *)f;	
	pthread_mutex_init(&temp -> mark ,  NULL);
    int i = 0;
	for( ; i < N; i++)
	{
    	  pthread_mutex_lock(&temp -> mark);
          temp -> num += 1;
          pthread_mutex_unlock(&temp -> mark);
	
	}
    pthread_exit(NULL);
}



