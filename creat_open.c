#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
	if(argc != 3)//Check number of arguments
	{
		printf("Invalid number of arguments!");
		exit(1);
	}
	int fd1, fd2, i;//File descriptors and Temporary descriptor
	char buff[500];//Character buffer ro store data
	fd1 = open(argv[1], 0);//Open file 1 passed the first argument in read_only mode
	i = read(fd1, buff, 500);//Reading the contents of file1 into char buff
	creat(argv[2], S_IRWXU);//Create file with name passed as second argument
	fd2 = open(argv[2], 1);//Open file 2 in write_only mode
	write(fd2, buff, i);//Write contents of char buffer into file 2
	close(fd2);//Close file 2
	close(fd1);//close file 1
	printf("\nRead from: %s \nWritten into: %s\nContent written: %s\n",argv[1], argv[2], buff);//Displaying program feedback
	return 0;
}