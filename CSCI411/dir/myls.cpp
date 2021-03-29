/*
*Name: Jon Tice
*
*Title: myls
*
*Description: A limited version of the ls command that will display if the file 
*is a directory, the permissions, file name, file size, and last modified date
*for all of the files in the given or current directory
*
*Date:3/21/18
*
*Class:CSCI411
*/

#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<time.h>

using namespace std;

int main(int argc, char* argv[])
{
	DIR * dir;

	struct dirent * sd;
	struct stat rd;
	char name[512];
	char curdir[1024];
	string slash;

	//check for amount of arguments given
	if(argc >= 2)
	{
		//open the given directory 
		dir = opendir(argv[1]);
		slash = argv[1];
	}
	else
	{
		//no arguments given so open current directory
		dir = opendir(".");
	}
	
	//check if the directory was successfully opened (if it is valid)
	if(dir == NULL)
	{
		cout<<"ERROR: could not open directory."<<endl;

		return 0;
	}
	//print the current working directory 
	getcwd(curdir, sizeof(curdir));
        cout<<"Current working dir: "<<curdir<<endl;

	//read each of the files in the directory
	//using the dirent struct to gain the file name and type	
	while((sd = readdir(dir)) != NULL)
	{
		//to get the correct information the full directory with file name
		//must be given to stat this is only if a directory is given
		if(argc >= 2)
		{
			//check for and append a '/' for the valid directory if not given 
			if(slash.substr((strlen(slash.c_str())-1)) == "/")	
				sprintf(name, "%s%s", argv[1], sd->d_name);
			else
				sprintf(name, "%s%c%s", argv[1], '/', sd->d_name);				
			
			stat(name, &rd);
		}
		else
		{
			stat(sd->d_name, &rd);
		}

		//check if the file is a directory
		if((sd->d_type) == DT_DIR)
                {
                        cout<<"DIR  ";
                }
                else
                {
                        cout<<"     ";
                }
		//Permissions
		printf((rd.st_mode & S_IRUSR) ? "r" : "-" );
		printf((rd.st_mode & S_IWUSR) ? "w" : "-" );
		printf((rd.st_mode & S_IXUSR) ? "x" : "-" );
		printf((rd.st_mode & S_IRGRP) ? "r" : "-" );
		printf((rd.st_mode & S_IWGRP) ? "w" : "-" );
                printf((rd.st_mode & S_IXGRP) ? "x" : "-" );
                printf((rd.st_mode & S_IROTH) ? "r" : "-" );
                printf((rd.st_mode & S_IWOTH) ? "w" : "-" );
		printf((rd.st_mode & S_IXOTH) ? "x" : "-" );
		//File Name
		cout.width(28);
		cout<<sd->d_name;
		//File Size
		cout.width(14);
		cout<<(long long)rd.st_size;
		//Last Modified Date
		cout.width(28);
                cout<<ctime(&rd.st_mtime);
	}
	//Close the directory
	closedir(dir);

	return 0;
}
