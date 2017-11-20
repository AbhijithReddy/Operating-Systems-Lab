#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;//Pointer for directory entery
int main(int argc, char const *argv[])
{
	char buff[100];///char buffer to store directory name
	DIR *dirp;//Pointer to the directory
	printf("\nEnter Directory Name:");//Read directory name from user
	scanf("%s", buff);
	dirp = opendir(buff);//opendir returns a pointer of DIR type
	if(dirp == NULL)
	{
		printf("Couldn't open directory with Name: %s\n", buff);
	}
	while(dptr = readdir(dirp))//Conditional to display contents of a directory
	{
		printf("%s\n", dptr->d_name);//Displays names of files in the directory
	}
	closedir(dirp);

	return 0;
}