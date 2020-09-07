/*
Author: Justin Rapczynski
Email: Justinrapczynski@my.unt.edu

Title: CSCE 4600 Hw4A Creating a deadpml


Discription: Simple c program used to create deadpml between two processes


You are able to tell that this program deadpmls because it is supposed to run 10 times and never will


Notes: To compile make sure to run the -pthread command in the command line
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void *p1(void *ptr); // declaration for below processes 
void *p2(void *ptr); // decleartion for below processes


typedef struct
{
  pthread_mutex_t m;
  pthread_mutex_t m1;
  pthread_mutex_t m2;
} pml;


//main function that calls for the processes
int	main(int argc, char *argv[])
{
  pthread_t thread[10];
  pthread_t tp1;
  pthread_t tp2;
  pml ptr;

  //initialize mutex
  pthread_mutex_init(&ptr.m1, NULL); 
  pthread_mutex_init(&ptr.m2, NULL);

  //Create the pthread
  pthread_create(&tp1, NULL, p1, &ptr);
  pthread_create(&tp2, NULL, p2, &ptr);
  
  //Join pthread
  pthread_join(tp1, NULL);
  pthread_join(tp2, NULL);
  return (0);
}


// these are the acutal processes

//process 1
void	*p1(void *ptr)
{
  pml *temp = (pml *)ptr;
  pthread_mutex_lock(&temp->m1);
  printf("Hello Im Process 1\n");
  pthread_mutex_lock(&temp->m2);
}

//process 2
void	*p2(void *ptr)
{
  pml *temp = (pml *)ptr;
  pthread_mutex_lock(&temp->m2);
  printf("Hello Im Process 2\n");
  pthread_mutex_lock(&temp->m1);
}

