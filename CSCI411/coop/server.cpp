/*
*Title:server.cpp
*
*Name:Jon Tice
*
*Description:The server program that will send and recieve messages 
*through the message queues
*
*Date:2/17/2018
*
*Class:CSCI411
*/
#include <stdio.h>
#include <cstdlib>
#include <sys/types.h>
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

int main ()
{
	int centralTemp = 60;
	int temp1 = -1;
	int temp2 = -1;
	int temp3 = -1;
	int temp4 = -1;

   	mqd_t qd_server1, qd_server2, qd_server3, qd_server4, qd_client1, qd_client2, qd_client3, qd_client4;   // queue descriptors
    	//int token_number = 1; // next token to be given to client

	char client_queue_name1[64] = "/clientT-1\\0'"; 
	char client_queue_name2[64] = "/clientT-2\\0'";
	char client_queue_name3[64] = "/clientT-3\\0'";
	char client_queue_name4[64] = "/clientT-4\\0'";

    	cout << "Server: Hello, World!\n";

    	struct mq_attr attr;

    	attr.mq_flags = 0;
    	attr.mq_maxmsg = MAX_MESSAGES;
    	attr.mq_msgsize = MAX_MSG_SIZE;
    	attr.mq_curmsgs = 0;

    	if ((qd_server1 = mq_open (SERVER_QUEUE_NAME_UNO, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        	cerr << "Server: mq_open (server)";
        	exit (1);
    	}
	if ((qd_server2 = mq_open (SERVER_QUEUE_NAME_DOS, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
                cerr << "Server: mq_open (server)";
                exit (1);
        }
	if ((qd_server3 = mq_open (SERVER_QUEUE_NAME_TRES, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
                cerr << "Server: mq_open (server)";
                exit (1);
        }
	if ((qd_server4 = mq_open (SERVER_QUEUE_NAME_CUATRO, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
                cerr << "Server: mq_open (server)";
                exit (1);
        }
    	char in_buffer [MSG_BUFFER_SIZE];
    	char out_buffer [MSG_BUFFER_SIZE];

    	while(temp1 != centralTemp){
        	// get temp from each queue from each client
        	if (mq_receive (qd_server1, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            		cerr << "Server: mq_receive";
            		exit (1);
        	}

		cout<<"Server: message received."<<in_buffer<<endl;

                temp1 = atoi(in_buffer);

		if (mq_receive (qd_server2, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
                        cerr << "Server: mq_receive";
                        exit (1);
                }

		cout<<"Server: message received."<<in_buffer<<endl;

                temp2 = atoi(in_buffer);

		if (mq_receive (qd_server3, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
                        cerr << "Server: mq_receive";
                        exit (1);
                }
		
		cout<<"Server: message received."<<in_buffer<<endl;

                temp3 = atoi(in_buffer);

		if (mq_receive (qd_server4, in_buffer, MSG_BUFFER_SIZE, NULL) == -1) {
                        cerr << "Server: mq_receive";
                        exit (1);
                }

        	cout<<"Server: message received."<<in_buffer<<endl;

		temp4 = atoi(in_buffer);
        	// send reply message to client
		centralTemp = (2*centralTemp + temp1+temp2+temp3+temp4)/6;
		//open the queues of the 4 client processes
        	if ((qd_client1 = mq_open (client_queue_name1, O_WRONLY)) == 1) {
            		cerr << "Server: Not able to open client queue";
            		continue;
        	}
		if ((qd_client2 = mq_open (client_queue_name2, O_WRONLY)) == 1) {
                        cerr << "Server: Not able to open client queue";
                        continue;
                }
		if ((qd_client3 = mq_open (client_queue_name3, O_WRONLY)) == 1) {
                        cerr << "Server: Not able to open client queue";
                        continue;
                }
		if ((qd_client4 = mq_open (client_queue_name4, O_WRONLY)) == 1) {
                        cerr << "Server: Not able to open client queue";
                        continue;
                }

          	//The following copies an integer into the c-string 
		sprintf(out_buffer, "%d", centralTemp);

		//send the central temp back to the clients      
        	if (mq_send (qd_client1, out_buffer, strlen (out_buffer), 0) == -1) {
           		cerr << "Server: Not able to send message to client";
            		continue;
        	}
		if (mq_send (qd_client2, out_buffer, strlen (out_buffer), 0) == -1) {
                        cerr << "Server: Not able to send message to client";
                        continue;
                }
		if (mq_send (qd_client3, out_buffer, strlen (out_buffer), 0) == -1) {
                        cerr << "Server: Not able to send message to client";
                        continue;
                }
		if (mq_send (qd_client4, out_buffer, strlen (out_buffer), 0) == -1) {
                        cerr << "Server: Not able to send message to client";
                        continue;
                }
        	//cout << "Server: sent temp " <<centralTemp<< " to client: " << in_buffer << endl;
        	//token_number++;
    	}
}
