/*
*Part B: Kernel Report
*
*Jon Tice
*
*Reports the behavior of the Linux kernel by inspecting the kernel state
*
*CSCI 411
*
*1/13/2018
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>

using namespace std;

int main()
{
	ifstream inpFile;
	string line;
	int count =0;
	int found, time, hours, minutes, seconds;

	//Host name
	inpFile.open("/proc/sys/kernel/hostname");
	//the file only contains the host name
	getline(inpFile, line);

	cout<<"A: Host Name: "<<line<<endl<<endl;

	inpFile.close();

	//Number of cpu's
	inpFile.open("/proc/cpuinfo");
	//the loop goes through each line in the file and count the instances of the 
	//word processor which will only appear once for each processor
	getline(inpFile, line);

	while(!inpFile.eof())
	{
		found = line.find("processor");
		//if found the the variable found will not be -1 (npos)
		if(found != -1)
			count++;

		getline(inpFile, line);
	}

        cout<<"B: Number of processing units: "<<count<<endl<<endl;

        inpFile.close();

	//Types and models
	inpFile.open("/proc/cpuinfo");

	cout<<"C: CPU(s) Type and model:"<<endl;
	//this loop will go through the file and check for the instances of the words 
	//that corespond to the data we need and will only appear once for their
	//respective processor 
        getline(inpFile, line);
	
        while(!inpFile.eof())
        {
                if(line.find("processor") != -1 || line.find("vendor_id") != -1 || line.find("model") != -1)
		{
			//print the file if the keywords are found
			cout<<line<<endl;
		}

		getline(inpFile, line);
        }
	
	cout<<endl;

        inpFile.close();

	//Linux Kernel Version
	inpFile.open("/proc/version");
	//the file only contains the version of the kernel
        getline(inpFile, line);

        cout<<"D: Linux Kernel Version: "<<line<<endl<<endl;

        inpFile.close();

	//System Time
	inpFile.open("/proc/uptime");

	cout<<"E:System time: "<<endl;
	//the first number in the file is the time (seconds) since the last re-boot
	inpFile>>line;

	time = atoi(line.c_str());
	//calculate the hours, minutes, and remaining seconds
	minutes = time/60;

	hours = minutes/60;

	seconds = time%60;

	cout<<"Time since last re-boot: "<<time<<" seconds which is equivalent to "<<hours<<" hours "<<minutes<<" minutes "<<seconds<<" seconds."<<endl;	
	//the second number in the file is the time (seconds) the system has been idle
	inpFile>>line;

        time = atoi(line.c_str());
	//calculate the hours, minutes, and remaining seconds
        minutes = time/60;

        hours = minutes/60;

        seconds = time%60;

        cout<<"Time in idle is "<<time<<" seconds which is equivalent to "<<hours<<" hours "<<minutes<<" minutes "<<seconds<<" seconds."<<endl<<endl;

	inpFile.close();

	//Memory Information
	inpFile.open("/proc/meminfo");
	//get the first number from meminfo which is MemTotal 
        getline(inpFile, line);

        cout<<"F: Memory information: "<<endl<<line<<endl;
	//get the second number from meminfo which is MemFree
	getline(inpFile, line);

	cout<<line<<endl<<endl;

        inpFile.close();

	return 0;
}
