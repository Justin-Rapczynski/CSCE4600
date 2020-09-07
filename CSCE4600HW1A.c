#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include<fcntl.h> 
#include<errno.h> 
extern int errno;

int main()
{

int x = 1;
pid_t pid;
time_t seconds;

printf("\n\nHello this is a simple c program showing some of the UNIX system calls,\nto show all these I will be explaining whats happening for each system \ncall made, Enjoy!\n\n\n");

printf("For the first command we will try the open command, I asked the computer to \nopen test1234.c and print out the integer that open retruns, if the number \nis positive, then you have that file in your directory, \nbut if you get a -1 you do not have that file:  ");
int fd = open("test1234.c", O_RDONLY);  
      
    printf("%d\n\n", fd); 
      
  
printf("We will now use the fork command to make a child and parent process....\n\n");
pid = fork();

if (pid == 0)
    {
        printf("This is the child made by fork()\n");
        time(&seconds);
       
        printf("To show the time() function we will use time() to print out how many seconds have passed since January 1, 1970\ntime() = %ld\n", seconds);
        printf("Now we will show the execl command by printing todays date and time:\n");   
        execl("/bin/date", "date", 0, (char*) NULL);    
    }
    else if (pid > 0)
        {
            printf("This is the parent made by fork()\n");
            printf("We will now use the wait() system call so the parent waits for the child....\n");
            wait(NULL);
        }

        else
            {
           	    perror("fork error");
            }

printf("\nFinally its time to end this program, to do this we will be using the exit() command. Goodbye");
exit(1);

}


