#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main()
{
	int fd[2];
	pid_t p;
	pipe(fd);//Create a pipe
	char buff[100];
	printf("Enter message to be sent: ");
	scanf("%s", buff);
	p = fork();
	if(p > 0)
	{
		close(fd[1]);//Closing writing end of pipe
		printf("Parent: Waiting for message!!\n");
		wait(NULL);
		close(fd[1]);//Closing writing end of pipe
		read(fd[0], buff, strlen(buff));//Reading fron Child
		printf("Parent: Received--- %s\n", buff);
		close(fd[0]);
	}
	else
	{
		printf("Child: Sending message --- %s\n", buff);
		close(fd[0]);//Closing reading end of pipe 
		write(fd[1], buff, strlen(buff));//Writing to Parent
		close(fd[1]);//Closing writing end of pipe
		exit(0);
	}
	return 0;
}