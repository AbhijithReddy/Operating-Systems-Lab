#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	pid_t process;// process is a variable that can store pid;
	process = fork();// invoking fork() which returns the pid to process;
	if (process == -1)//If error arises
	{
		printf("Error while invoking fork()");
		exit(1);//Exit after displaying error message
	}
	if (process == 0)//fork returns 0 for child process
	{
		printf("\nC: Inside Child process! ---pid: %d, parent pid: %d\n",getpid(), getppid());
	}
	else
	{
		printf("\nP: Inside Parent process ---pid: %d, parent pid: %d\n", getpid(), getppid());
		wait(NULL);//Parent waits till the child terminates
		printf("\nP: Child terminated!\n");//Statment executes after Child terminates
	}
	return 0;
}
