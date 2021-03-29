/*
//Title: Lab: Producer Consumer
//
//Name: Jon Tice
//
//Description: A program solution to the bounded buffer problem using semaphores
//
//Class:CSCI411
//
//Date:2/6/2018
*/
#include<pthread.h>
#include<cstdlib>
#include<cstring>
#include"buffer.h"
#include<semaphore.h>
#include<iostream>
#include<unistd.h>

using namespace std;

int count;
buffer_item buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
sem_t emptySpaces, fullSpaces;

//
//Name:buffer_init
//
//Description:Creates the mutex and two semaphores for the program
//
//Parameters:None
//
//Return Value:None
//
void buffer_init()
{
	//initialize the count, mutex and semaphores
	count = 0;

	pthread_mutex_init(&mutex, NULL);

	sem_init(&fullSpaces, 0, 0);
	sem_init(&emptySpaces, 0, BUFFER_SIZE);
}
//
//Name:insert_item
//
//Description:Inserts the passed item into the buffer
//
//Parameters:buffer_item item
//
//Return Value: int
//
int insert_item(buffer_item item)
{
	//lock the mutex
	pthread_mutex_lock(&mutex);
	if(count < BUFFER_SIZE)
	{
		//add the item to the buffer
		buffer[count] = item;
		count++;
		return 0;
	}
	else
	{
		return -1;
	}
	//unlock the mutex
	pthread_mutex_unlock(&mutex);
}
//
//Name:remove_item
//
//Description:Removes the item from the buffer
//
//Parameters:buffer_item *item
//
//Return Value:int
//
int remove_item(buffer_item *item)
{
	pthread_mutex_lock(&mutex);
	if(count > 0)
	{
		*item = buffer[count-1];
		count--;
		return 0;
	}
	else
	{
		return -1;
	}
	pthread_mutex_unlock(&mutex);
}
//
//Name:producer
//
//Description:Produces items to put in the buffer
//
//Parameters:void *param
//
//Return Value:None
//
void *producer(void *param)
{

	buffer_item item;

	while(true)
	{
		sleep(1);
		//generate the random number and 
		item = rand();
		//decrement empty spaces
		sem_wait(&emptySpaces);

		if(insert_item(item) == -1)
			cout<<"Error Could Not Insert."<<endl;
		else
			cout<<"Producer Produced Item "<<item<<" Thread No: "<<*((int *)param)<<endl;
		//increase full spaces
		sem_post(&fullSpaces);
		
	}
	
}
//
//Name:consumer
//
//Description:Removes items that are in the buffer
//
//Parameters:void *param
//
//Return Value:None
//
void *consumer(void *param)
{
        buffer_item item;

        while(true)
        {
                sleep(1);
		//decrease full spaces
		sem_wait(&fullSpaces);

	        if(remove_item(&item) == -1)
        	        cout<<"Error Could Not Remove."<<endl;
		else
                	cout<<"Consumer Consumed  Item "<<item<<" Thread No: "<<*((int *)param)<<endl;
		//increase empty spaces
		sem_post(&emptySpaces);
        }

}

int main(int argc, char * argv[])
{
	//if the proper amount of arguments are not given then exit
	if(argc != 4)
	{
		cout<<"Improper amount of arguments entered. Exiting."<<endl;
		return 0;
	}
	//get the respective arguments
	int slp = atoi(argv[1]);
	int numPro = atoi(argv[2]);
	int numCos = atoi(argv[3]);
	/*
	cout<<slp<<endl;
	cout<<numPro<<endl;
	cout<<numCos<<endl;
	*/
	//initiate the buffer
	buffer_init();
	//create the two threads that will be used
	pthread_t *proThread = new pthread_t[numPro];
	pthread_t *conThread = new pthread_t[numCos];
	//create the number of consumer threads passed in argv[2]
	int *pro = new int[numPro];
	for(int i = 0; i < numPro; i++)
	{
		pro[i] = i;
		
		pthread_create(&proThread[i], NULL, producer, &pro[i]);

		//pthread_join(proThread[i], NULL);
		
		cout<<"Creating Producer "<<i<<endl;
	}
	//create the number of consumer threads passed in argv[3]
	int *cos = new int[numCos];
        for(int i = 0; i < numCos; i++)
        {
                cos[i] = i;
                
                pthread_create(&conThread[i], NULL, consumer, &cos[i]);

		//pthread_join(conThread[i], NULL);

                cout<<"Creating Consumer "<<i<<endl;
        }	
	//sleep for the passed amount of seconds in argv[1]
	sleep(slp);

	delete [] pro;
	delete [] cos;

	cout<<"Finished"<<endl;	
	
	return 0;
}
