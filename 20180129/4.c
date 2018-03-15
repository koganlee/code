#include "apue.h"
struct flag{
   pthread_mutex_t mark;
   long num;
};
#define N 50000000
void *pthread_function(void *num);
int main()
{
    pthread_t a_thread;
	long  num = 0;
    int res = pthread_create(&a_thread, NULL, pthread_function,&num);
	if(res != 0) {
		printf("thread creation failed\n");
		return -1;
	}
    int n = 0;
     for(n = 0; n < N; n++)
	 {
          num += 1;
	 }
	 pthread_join(a_thread, NULL);
     printf("num = %ld\n", num);
     pthread_exit(&a_thread);
    return 0;
}



void *pthread_function(void *num)
{
    int i = 0;
	for( ; i < N; i++)
	{
       *(long *) num += 1;
	}
    pthread_exit(NULL);
}



