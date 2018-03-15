#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sig(int sig)
{


}



void timer(int sig)
		  9 {
				   10      time_t t;
				    11      time(&t);
					 12      struct tm *p = gmtime(&t);
					  13      printf("%04d-%02d-%02d  %02d：%02d:%02d\n", (1900+p-> tm_year), (1 + t ->tm_mon),p->tm_mday, (8 + t -> tm_hour),
									   14                      t -> tm_min,  t -> tm_sec);
					   15
							    16 }

