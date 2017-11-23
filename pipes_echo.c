#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	int fd1[2];
	int fd2[2];
	int test;
	pid_t p;
	pipe(fd1);
	pipe(fd2);
	char message[100];
	printf("Enter message to be sent by Server: ");
	scanf("%s", message);
	p = fork();
	if(p > 0) //parent process
	{
		char buff[100];
		close(fd1[0]);//Close reading end of pipe1
		write(fd1[1], message, strlen(message));//Write message to writing end of pipe1
		printf("Server: Message sent succesfully\n");
		close(fd1[1]);//Close writing end of pipe1
		wait(NULL);//Waiting for child to send a string i.e echo message
		close(fd2[1]);//CLose writing end of pipe2
		read(fd2[0], buff, 100);
		printf("Server: Received--- %s\n", buff);
		close(fd2[0]);
	}
	else
	{
		char buff[100];
		close(fd1[1]); //Close writing end of pipe1
		read(fd1[0], buff, 100);//Read a string using pipe1
		printf("Client: Received--- %s\n", buff);
		close(fd1[0]);//Close both reading ends
		close(fd2[0]);
		write(fd2[1], buff, strlen(buff));//Write a string using pipe2
		printf("Client: Sent echo\n");
		close(fd2[1]);//Close writing end of pipe2
		exit(0);
	}
	return 0;
}