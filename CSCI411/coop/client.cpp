/*
*Title:client.cpp
*
*Name:Jon Tice
*
*Description:The client program that will send and recieve updates on 
*the temperature from the server
*
*Date:2/17/2018
*
*Class:CSCI411
*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <cstring>
#include <iostream>

#define SERVER_QUEUE_NAME_UNO   "/Ticeserver1"
#define SERVER_QUEUE_NAME_DOS   "/Ticeserver2"
#define SERVER_QUEUE_NAME_TRES   "/Ticeserver3"
#define SERVER_QUEUE_NAME_CUATRO   "/Ticeserver4"
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

using namespace std;

int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		cout<<"Temperature must be passed as first argument for client and the number of the client (1,2,3, or 4) as the second. Exiting."<<endl;
		exit(1);
	}

  	//  char client_queue_name [64];
   	mqd_t qd_server, qd_client;   // queue descriptors

	int temp = atoi(argv[1]);
	int numCli = atoi(argv[2]);

	string str_client_queue_name;

	char tempS[10];
	strcpy(tempS, argv[1]);

	string cenTemp = "test";

    	// create the client queue for receiving messages from server
    	char client_queue_name[64];
	//create the name from the client number given in command line
	switch(numCli)
	{
		case 1:
			
		case 2:
		
		case 3:
		
		case 4:
			str_client_queue_name = "/clientT-" + to_string(numCli) + "\\0'";
			break;
		default:
			cout<<"Valid client number not entered. exiting."<<endl;
			return 0;
	}

	//string str_client_queue_name = "/clientT-" + to_string(numCli) + "\\0'";
	strcpy(client_queue_name, str_client_queue_name.c_str());

    	struct mq_attr attr;

    	attr.mq_flags = 0;
    	attr.mq_maxmsg = MAX_MESSAGES;
    	attr.mq_msgsize = MAX_MSG_SIZE;
    	attr.mq_curmsgs = 0;

    	if ((qd_client = mq_open (client_queue_name, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        	cerr<<"Client: mq_open (client)"<<endl;
        	exit (1);
    	}
	//open the corresponding queue to the client number
	switch(numCli)
        {
                case 1:
			if ((qd_server = mq_open (SERVER_QUEUE_NAME_UNO, O_WRONLY)) == -1) {
                		cerr<<"Client: mq_open (server)"<<endl;
                		exit (1);
        		}
			break;
                case 2:
			if((qd_server = mq_open (SERVER_QUEUE_NAME_DOS, O_WRONLY)) == -1) {
                                cerr<<"Client: mq_open (server)"<<endl;
                                exit (1);
                        }
			break;
                case 3:
			if((qd_server = mq_open (SERVER_QUEUE_NAME_TRES, O_WRONLY)) == -1) {
                                cerr<<"Client: mq_open (server)"<<endl;
                                exit (1);
                        }
			break;
                case 4:
                        if((qd_server = mq_open (SERVER_QUEUE_NAME_CUATRO, O_WRONLY)) == -1) {
                                cerr<<"Client: mq_open (server)"<<endl;
                                exit (1);
                        }
                        break;
                default:
        		cout<<""<<endl;                
        }

    	char in_buffer [MSG_BUFFER_SIZE];

    	//printf ("Ask for a token (Press <ENTER>): ");

    	//char temp_buf [10];

    	while(cenTemp != "fin") {

		cout<<numCli<<" is sending: "<<tempS<<endl;		
        	// send message to server
        	if (mq_send (qd_server, tempS , strlen(tempS), 0) == -1) {
             		cerr<<"Client: Not able to send message to server";
            		continue;
        	}

        	if (mq_receive (qd_client, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
             		cerr<<"Client: mq_receive";
            		exit (1);
        	}
        	// display token received from server
        	cout << "Client: Token received from server: " <<  in_buffer << endl;

		cenTemp = in_buffer;

		if(cenTemp != "fin")
		{
			temp = (temp*3+2*atoi(cenTemp.c_str()))/5;
			cout<<"The new temp is: "<<temp<<endl;
		}
    	}


    	if (mq_close (qd_client) == -1) {
        	cerr<<"Client: mq_close";
        	exit (1);
    	}

    	if (mq_unlink (client_queue_name ) == -1) {
         	cerr<<"Client: mq_unlink";
        	exit (1);
    	}
    	cout << "Client: bye\n";

    	exit (0);
}
