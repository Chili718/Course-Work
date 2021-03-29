/*
*Program 6: program6.cpp
*
*Jon Tice
*
*Reads from a user entered file, creates the graph, preforms topological sort,
*and prints out the sorted data such that the prerequisites for every course
*appear before that course.
*
*CSCI271
*
*4/17/2017
*/
#include"graph.h"
using namespace std;

int main()
{
	graph one;	

	one.createGraph();

	//one.printGraph();

	one.topologicalSort();

	//one.clearGraph();

	//one.printGraph();

	return 0;
}
