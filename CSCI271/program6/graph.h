/*
*Program 6: graph class file
*
*Jon Tice
*
*The header/implementation file for the iter class
*
*CSCI271
*
*4/18/2017
*/
#ifndef graph_h
#define graph_h
#include<list>
#include<fstream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

class graph
{
	public:
		//Constructor
		graph();
		//Destructor
		~graph();
		bool isEmpty();
		void createGraph();
		void clearGraph();
		void printGraph();
		void topologicalSort();
		
	private:
		int maxSize;
		int gSize;
		list<string> *graphT;
		int findIndex(string vertex);	
};
//Constructor
graph::graph()
{
        maxSize = 500;
        gSize = 0;
        graphT = new list<string>[maxSize];

}
//Destructor
graph::~graph()
{
        clearGraph();
}
//
//Function Name:
//
//Description: returns true if graph is empty
//
//Parameters: none
//
//Return Value: bool
//
bool graph::isEmpty()
{
	return (gSize == 0);
}
//
//Function Name: createGraph
//
//Description: creates a graph from the file entered by the user
//
//Parameters: none
//
//Return Value: none
//
void graph::createGraph()
{
	ifstream inpFile;
	char terminate = '#';
	char fileName[50];

	char vertex[10];
	//if this is called when the graph has data then the 
	//existing data will be deleted
	if(gSize != 0)
		clearGraph();

	cout<<"Enter file name: ";
	cin>>fileName;

	inpFile.open(fileName);
	if(!inpFile)
	{
		cout<<"ERROR: File could not be opened"<<endl;
		return;
	}

	inpFile>>vertex;

	while(!inpFile.eof() && gSize < maxSize)
	{
		while(vertex[0] != terminate)
		{
			//initially pushes the course as the head then followed by its edges
			//cout<<vertex<<endl;
			graphT[gSize].push_back(vertex);
			inpFile>>vertex;
		}
		gSize++;
		inpFile>>vertex;
	}
	inpFile.close();
	//cout<<gSize<<endl;
}
//
//Function Name: clearGraph
//
//Description: deletes the contents of the graph
//
//Parameters: none
//
//Return Value: none
//
void graph::clearGraph()
{
	for(int i = 0; i < gSize; i++)
	{
		graphT[i].clear();
	}
	gSize = 0;
}
//
//Function Name: printGraph
//
//Description: prints the contents of the graph
//
//Parameters: none
//
//Return Value: none
//
void graph::printGraph()
{
	list<string>::iterator trav;
	for(int j = 0; j < gSize; j++)
	{
		trav = graphT[j].begin();
		while(trav != graphT[j].end())
		{
			cout<<*trav<<" ";
			trav++;
		}
		cout<<endl;
	}
}
//
//Function Name: topologicalSort
//
//Description:preforms Kahn's version of topological sort on the graph
//then prints out the sorted data
//Parameters: none
//
//Return Value: none
//
void graph::topologicalSort()
{
	vector<int> in_degree(gSize, 0);
	vector<string> order;
	list<string>::iterator itr;
	list<string>::iterator itr2;
	int count;

	for(int q = 0; q < gSize; q++)
	{
		//the head of the list is the course and what comes after
		//are the prerequisites 
		itr = graphT[q].begin();
		itr++;
		//moves through list and counts the number of indegrees for each vertex	
		for(itr; itr != graphT[q].end(); itr++)
		{
			in_degree[findIndex(*itr)]++;
		}	
	}

	/*
	for(int i = 0; i < in_degree.size(); i++)
        {
                cout<<in_degree[i]<<endl;
        }
	*/

	//create a queue to hold all vertecies with in-degree 0
	queue<string> x;
	
	for(int i = 0; i < gSize; i++)
	{
		itr = graphT[i].begin();
		if(in_degree[i]==0)
			x.push(*itr);
	}
	
	while(!x.empty())
	{
		//dequeue and add element to the ordered list
		string y = x.front();

		x.pop();
	
		order.push_back(y);
		//it will then move through the elements neighboring nodes
		//and decrease their in-degree by one and if then they are zero
		//they will be added to the queue
		itr2 = graphT[findIndex(y)].begin();
		itr2++;

		for(itr2; itr2 != graphT[findIndex(y)].end(); itr2++)
		{
			if(--in_degree[findIndex(*itr2)]==0)
	                        x.push(*itr2);
		}
		//increases the number of visited vertices
		count++;
	}

	//checks for cycle in graph
	if(count != gSize)
	{
		cout<<"There is a cycle in the graph."<<endl;
		return;
	}
	//prints in topological order
	for(int i = 0; i < order.size(); i++)
	{
		cout<<order[i]<<endl;
	}
}
//
//Function Name:findIndex
//
//Description: takes the passed string and finds its array index using
//the very inefficient linear search just for it to run
//Parameters: string vertex
//
//Return Value: index of the strings position in array
//
int graph::findIndex(string vertex)
{
	list<string>::iterator find;

	for(int m = 0; m < gSize; m++)
	{
		find = graphT[m].begin();
		if(*find == vertex)
		{
			//cout<<m<<endl;
			return m;
		}
	}
	//if the item is not found
	return -1;
}
#endif
