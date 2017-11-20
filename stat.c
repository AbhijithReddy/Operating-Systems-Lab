#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argc, char const *argv[])
{
	if(argc != 2)//Check if filename is passed at runtime
	{
		printf("Invalid number of arguments!\n");
		exit(1);
	}
	struct stat filestat;//Declare struct variable filestat of type stat
	stat(argv[1], &filestat);//passing filename and pointer to struct variable to stat() system call
	printf("Information of File: %s\n", argv[1]);//File name passed as argument
	printf("File size : %lld bytes\n", filestat.st_size);//Total size, in bytes
	printf("Number of links: %d\n", filestat.st_nlink);//Number of hardlinks
	printf("File inode: %llu\n", filestat.st_ino);//Inode number
	printf("Mode is: %d\n", filestat.st_mode);//Protection
	printf("Device id: %d\n", filestat.st_dev);//Id of device containing the file
	printf("User id: %d\n", filestat.st_uid);//userid of owner
	printf("Group id: %d\n", filestat.st_gid);//groupid of owner
	return 0;
}