//This program creates five processors and performs 200 proccesses in a schedule system
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdbool.h>
void SyntheticProcess(double time);

#define MAX 50000.00 //Maximum number of seconds a proccess can be in GHz/Sec
#define MIN 0.01 //Minimum number of seconds a proccess can be in GHz/Sec

#define FILEMAX 8000.00 //Maximum file size in Mb
#define FILEMIN 0.25 // Minimum File size in Mb

int main() 
{ 
    int pid1, pid2, pid3, pid4, pid5;
	double processTime, fileSize;
	bool paON = 0, pbON = 0, pcON = 0, pdON = 0, peON = 0;


srand(time(NULL));
    for(int i = 1; i <= 200; i++)
	{
        //Right now we are assuming all processors are 1Ghz so they perform 1 billion cycles per second 
		processTime = ((double)(rand() * (MAX - MIN)/RAND_MAX - MIN));

		//Generate a random file size between 0.25 - 8000 mb
		fileSize = ((double)(rand() * (FILEMAX - FILEMIN)/RAND_MAX - FILEMIN));
    while(1)
    {    
    
        if(!(pid1 = fork()))
        { // child proccess 1

       
            
                        paON = 1;
						printf("Processor: PA, Process: %d, Size: %.2f MB\n", i, fileSize);
						SyntheticProcess(processTime);
						paON = 0;
						exit(0);
                    
        

        } 
  

        else if (!(pid2 = fork())) 
        { // child proccess 2
        
                        pbON = 1;
						printf("Processor: PB, Process: %d, Size: %.2f MB\n", i, fileSize);
						SyntheticProcess(processTime);
						pbON = 0;
						exit(0);
		}
          
    


    else if (!(pid3 = fork())) 
    { //child proccess 3
      
       pcON = 1;
						printf("Processor: PC, Process: %d, Size: %.2f MB\n", i, fileSize);
						SyntheticProcess(processTime);
						pcON = 0;
						exit(0);
	}

     
  else if (!(pid4 = fork())) 
    { //child proccess 3
      
       
            
        	pdON = 1;
						printf("Processor: PD, Process: %d, Size: %.2f MB\n", i, fileSize);
						SyntheticProcess(processTime);
						pdON = 0;
						exit(0);

    } 
    else if (!(pid5 = fork())) 
    { //child proccess 3
      
            
           peON = 1;
					printf("Processor: PE, Process: %d, Size: %.2f MB\n", i, fileSize);
					SyntheticProcess(processTime);
					peON = 0;
					exit(0);
      

    } 
    else 
    {  //parent

        wait(&pid1);
        wait(&pid2);
        wait(&pid3);
        wait(&pid4);
        wait(&pid5);
    
    }
}

} 

    return 0; 
} 


void SyntheticProcess(double time)
{
	usleep(time);
}