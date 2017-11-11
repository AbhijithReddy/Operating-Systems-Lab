#include<stdio.h>
#include<unistd.h>
int main()
{
 int key = 3; // factorial for key is returned
 int fact = 1; //result is intialized to 1
 int i = 1; // Intializing i for FOR loop
 if(fork() == -1) //fork() returns -1 if error in creation
 {
  printf("Error Creating Fork!");
 }
 if(fork() == 0) //fork() returns 0 for child process
 {
  printf("Inside Child Process!");
 }
 else
 {
  if(key == 0) //Factorial of 0 is 1
  {
   printf("Factorial of %d is %d", key, fact);
  }
  else //for key > 0 ==> fact = fact X i 
  {
   for(i = 1; i <= key; i++)
   {
    fact = fact * i;
   }
   printf("Factorial of %d is %d", key, fact);
  }
 }
return 0;
} //End of main

