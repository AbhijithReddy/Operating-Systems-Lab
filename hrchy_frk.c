#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
 pid_t parent, child; // pid_t is a data type to store process ids
 parent = fork();
 if(parent == -1)//pid returns -1 if error occurs during creation
 {
  printf("Error executing Fork! @Parent");
  exit(1);
 } 
 if(parent == 0)//Child process returns 0
 {
  child = fork();//Executing fork on child process
  if(child == -1)
  {
   printf("Error executing Fork! @Child");
  }
  if(child == 0)//Inside Grand Child resulted on forking Child
  {
   printf("\npid: %d, Parent-pid: %d ---grandchild\n", getpid(), getppid());//return process ids of the current process and it's parent.
  }
  else//Child block starts here
  {
   printf("\npid: %d, Parent-pid: %d ---child\n", getpid(), getppid());
   wait(NULL);//Child waits tills garendchild finishes execution!
  }
 }
 else//If pid > 0, refers to parent process after fork
 {
  printf("\npid: %d, Parent-pid: %d ---parent \n", getpid(), getppid());//returns process ids of the current porcess and it's parent process.
 wait(NULL);//Parent waits till child completes execution!
 }
return 0;
}
 
