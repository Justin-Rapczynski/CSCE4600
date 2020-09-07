#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>


int main() 
{ 
    FILE *fptr;
    pid_t pid;
    int counter = 0, readnum;
    int status;

    
for (int kid = 0; kid < 3; ++kid) {
    int pid = fork();
    if(pid < 0){
        exit(EXIT_FAILURE);
    }
    else if (pid > 0){
        wait(NULL);/* Parent process */
    }
    else{
        while(counter < 200)
        {
           
            fptr = fopen("fileD.txt", "r");
            fscanf(fptr, "%d", &readnum) ;
            fclose(fptr);
        
                printf("%d", readnum);
                printf(" pid = %d\n", getpid()); 
                
                readnum++;
        
                    fptr = fopen("fileD.txt", "w");
                    fprintf(fptr, "%d", readnum);
                    fclose(fptr); 
        
                    counter++;
        }
        exit(EXIT_SUCCESS);
        counter == 0;
    }
}

for (int kid = 0; kid < 3; ++kid) {
    int status;
    pid_t pid = wait(&status); // kids could be ready in any order
}

    return 0; 
} 