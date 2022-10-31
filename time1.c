#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
void myHandler(int signum)
{
printf("inside myHandler function\n");
printf("signal raised and handled\n");
printf("signal number = %d\n",signum);
}
int main()
{
int count=0;
signal(14,myHandler);
printf("Linux kernal timers\n");
alarm(10);
  struct itimerval t1;
  t1.it_interval.tv_sec=5;
  t1.it_interval.tv_usec=0;
  t1.it_value.tv_sec=10;
  t1.it_value.tv_usec=0;
  setitimer(ITIMER_REAL,&t1,NULL);
  while(1)
  {
  struct itimerval t2;
getitimer(ITIMER_REAL, &t2);
  printf("in while loop\n");
  printf("Timer = %ld s and %ld usec\n",t2.it_value.tv_sec,t2.it_value.tv_usec);
  count++;
  sleep(1);
  }
  }
  
