#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main()
{
    int fd;
    int fd1;
    char c[1];
    //char c = (char *) calloc(100, sizeof(char));
    time_t seconds;

    fd = open("fileA.txt", O_RDONLY);
    fd1 = open("fileB.txt", O_CREAT | O_WRONLY);

    if(fd == -1){
        
        printf("Failed to open and read the file. \n");
        exit(1);
        printf("Failed to create and open the file. \n");
        exit(1);
    }

    if(fd1 == -1){
        printf("Failed to create and open the file. \n");
        exit(1);
    }

    while (read(fd, &c, 1) != NULL){

        write(fd1, &c, 1);        


    }

  
return 0;

}