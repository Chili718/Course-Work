/*
*Simple Shell
*
*Jon Tice
*
*Allows the user to preform various tasks with the shell created. 
*
*CSCI 411
*
*1/27/2018
*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<unistd.h>
#include<fstream>
#include<fcntl.h>
#include<signal.h>
#include<sys/wait.h>

using namespace std;
//function that will contain what we want to do when a signal is generated
void signal_callback_handler(int signum);

int main()
{
	string command, firstH, secondH, combine, line;
	int rr;
	fstream history;
	//open a file that will hold the commands that have been run
	history.open("history.txt", ios::out);	

	history<<"History of the commands executed: "<<endl;

	cout<<"\tticej system shell\n"<<endl;

	signal(SIGINT, signal_callback_handler);

	while(command != "quit")
	{
		
		if(command == "clr")
		{
			system("clear");
		}
		else if(command.find("help") == 0)
		{
			//this string contains all the supported commands
			string supported = "myprocessallprocesseschgdclrdirenvironquit";
			if(command == "help")
			{
				cout<<"List of commands: "<<endl;
				cout<<"myprocess\nallprocesses\nchgd <directory>\nclr\ndir <directory>\nenviron\nquit\nhelp";
			}
			else
			{
				//get the command that help is being issued for
                        	firstH = command.substr(5, command.length());
				if(supported.find(firstH) != -1)
				{
					cout<<"myprocess - returns the id of the current process"<<endl;
					cout<<"allprocesses - displays the current processes"<<endl;
					cout<<"chgd <directory> - change the current directory to <directory>"<<endl;
					cout<<"clr - clear the screen"<<endl;
					cout<<"dir <directory> - display the contents of <directory> or the current if no directory is given"<<endl;
					cout<<"environ - list the environment strings"<<endl;
					cout<<"quit - exit the shell"<<endl;
				}
				else
				{//if it is help for a command that is not supported run man with the command
					firstH = "man " + firstH;
					system(firstH.c_str());
				}
			}
		}
		else if(command == "environ")
		{
			system("env");
		}
		else if(command == "allprocesses")
		{
			system("ps");
		}
		else if(command == "myprocess")
		{
			cout<<"Our current process ID is: "<<getpid()<<endl;
		}
		else if(command.find("chgd") == 0)
		{
			if(command.length() > 5)
			{
				//gain the directory from the command
				firstH = command.substr(0, 3);
                        	secondH = command.substr(5, command.length());
	
				rr = chdir(secondH.c_str());
				//if the value returned by chdir is < 0 then the directory has not been changed
				if(rr < 0)
					cout<<"ERROR: could not change directory."<<endl;
			}
			//if the directory is changed the cat command which will display the history will not work
			//becuase the history.txt file will not be in that directory
		}
		else if(command.find("dir") == 0)
		{
			if(command.length() > 4)
                        {
				//gain the directory from the command
                                firstH = command.substr(0, 2);
                                secondH = command.substr(4, command.length());

                                combine = "ls -al " + secondH;

				system(combine.c_str());
                        }
			else
			{//if no directory is given just display the contents of the current directory
				system("ls -al");
			}
		}
		else if(command.find("repeat") == 0)
		{
			if(command.find(" > ") != -1)
			{
				//manipulate the string to get the file name and text in its own variables
				firstH = command.substr(command.find('"')+1, command.length());
				secondH = firstH.substr(firstH.find(">")+2,firstH.length());
                                firstH = firstH.substr(0, firstH.find('"'));
				//save stdout to return to later
				int save = dup(1);				
				//open the file given
				int file = open(secondH.c_str(), O_APPEND | O_WRONLY);
				if(file < 0)
					cout<<"ERROR invalid file name "<<endl;

				//redirect standard output to the file
				if(dup2(file, 1) < 0)
					cout<<"ERROR: not able to redirect standard output"<<endl;
				//send the text to the file
				cout<<firstH<<endl;

				//return standard output to the screen
				if(dup2(save, 1) < 0)
					cout<<"ERROR: not able to redirect standard output"<<endl;

				close(file);
			}
			else
			{
				firstH = command.substr(command.find('"')+1,command.length());
				firstH = firstH.substr(0, firstH.find('"'));
				cout<<firstH<<endl;
			}
		}
		else if(command == "hiMom")
		{
			int filed[2];
			int value;

			pipe(filed);
			pid_t pid = fork();

			if(pid == 0)
			{//if child process
				close(filed[0]);

				value = 100;
				//send the value to the parent
				write(filed[1], &value, sizeof(value));

				close(filed[1]);

				cout<<"Child("<<getpid()<<") sent the value: "<<value<<endl;

				//exit(EXIT_SUCCESS);

			}
			else
			{//if parent process
				close(filed[1]);
				//recieve the value from the child
				read(filed[0], &value, sizeof(value));

				close(filed[0]);

                                cout<<"Parent("<<getpid()<<") read the value: "<<value<<endl;

				wait(NULL);

				//exit(EXIT_SUCCESS);

			}

			//after this command is run there is a weird glitch where the user will have to enter 
			//quit twice to end the program and it prints out the history twice

			//close(filed[0]);
			//close(filed[1]);			
		}
		else
		{
			system(command.c_str());
		}
		
		cout<<"ticej:~$";
		getline(cin, command);
		//write the line entered to the history file
		history<<command<<endl;
	}
	
	history.close();
	//display the commands run in the history file
	system("cat history.txt");

	return 0;
}
/*
*Name:signal_callback_handler
*
*Description:Calls this function when ctrl-c signal is generated
*
*Parameter: int signum
*
*Return Value: None
*/
void signal_callback_handler(int signum)
{
	cout<<"\nCtrl C was pressed, shell exiting."<<endl;

	system("cat history.txt");

	//exit the program
	exit(signum);
}
