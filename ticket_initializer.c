#include<stdio.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<semaphore.h>
#include<sys/mman.h>
#include<fcntl.h>




int main()
{
        int sd,cd,num,*ptr,shm_fd;
        int count;
        sem_t *sem_fd;
        char rbuf[256];
        struct sockaddr_in s1;



    if((shm_fd=shm_open("/smriti1711",O_RDONLY,0777))==-1)
        {
                perror("shm_open");
        }
     if((sem_fd=sem_open("/Misthi12",O_RDWR|O_CREAT,0777,1))==SEM_FAILED)
           {
                perror("sem_open");
          }




        if((sd=socket(AF_INET,SOCK_STREAM,0))==-1)
        {
                perror("socket");
        }
        s1.sin_family=AF_INET;
        s1.sin_port=9979;
        s1.sin_addr.s_addr=inet_addr("10.75.58.32");
        if(bind(sd,(struct sockaddr *)(&s1),sizeof(s1))==-1)
        {
                perror("bind");
        }
        listen(sd,50);
        printf("Server is in listening mode\n");
        while(1)
        {

                printf("waiting for clients\n");
                cd=accept(sd,0,0);
                count++;
                printf("client request accepted\n");
                if(fork() == 0)
                {
                        while(1)
                        {
                                read(cd,rbuf,256);
                                printf("read data from client %d=%s\n",count,rbuf);
                                sem_wait(sem_fd);
                                ptr=mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
                                printf("Number of avaialable tickets = %d\n",*ptr);
                                if(*ptr>=atoi(rbuf))
                                {
                                 printf("tickets are avaliable\n");
                                 sleep(20);
                                 *ptr=*ptr-atoi(rbuf);
                                write(cd,"Tickets are booked",256);
                                printf("remaining tickets are:-%d\n",*ptr);
                                }
                                else
                                {
                                        write(cd,"Tickets are not booked",256);
                                }
                                sem_post(sem_fd);
                                munmap(ptr,4096);
                        }
                }
                                else
                                {
                                close(cd);
                                sem_post(sem_fd);
                                                                }
                                                                        }
                                                                                close(sd);
                                                                                }          
