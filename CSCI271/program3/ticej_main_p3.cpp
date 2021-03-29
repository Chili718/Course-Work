/*
*Program 3: Test Main
*
*Name: Jon Tice
*
*Description: Provides a list of options for the user to interact with
*a BST
*
*Class: CSCI271
*
*Date: 3/15/2018
*/
#include<fstream>
#include"ticej_BinaryST_p3.h"
#include<cstring>

template<class dataT>
void visit(Node<dataT>* passedMain);

int main()
{
	//the users choice for the prompt
	char inp;
	//input for option 2 and 3 
	char sert[21];
	//name of the file for option 1 
	string fileNME;
	//Data stored in each node will be a character 
	//string of at most 20 charaters plus one for null terminator
	BinaryST<char[21]> one;
	//node pointer for option 4
	Node<char[21]>* rem;
	//fstream variable for option 1
	fstream fle;

	while(true)
	{

		cout<<"-----------"<<endl;
		cout<<"1-Insert from a file."<<endl;
		cout<<"2-Insert from the keyboard."<<endl;
		cout<<"3-Find a value."<<endl;
		cout<<"4-Delete a value."<<endl;
		cout<<"5-Print inorder."<<endl;
		cout<<"6-Print preorder."<<endl;
		cout<<"7-Print postorder."<<endl;
		cout<<"8-Exit"<<endl;
		cout<<"----------"<<endl;	
		cout<<"Enter your choice: ";
		cin>>inp;
		//the input should only be a single character this ignores the rest of 
		//the input after the first character i.e. 1864 would be taken as 1
		cin.ignore(256, '\n');

		cout<<endl;

		switch(inp)
		{
			case '1':
				cout<<"Enter the name of the file you would like to insert from: ";
				cin>>fileNME;
				
				fle.open(fileNME.c_str(), ios::in);

				if(!fle)
				{	
					cout<<"ERROR: File could not be opened."<<endl;
				}
				else
				{
					//read the first line from the file
					fle>>sert;

					while(!fle.eof())
					{
						one.insert(sert);
						fle>>sert;
					}
				
					cout<<endl<<"The data from the file was inserted."<<endl;
				}

				fle.close();				

				break;
			case '2':
				cout<<"Enter the data you would like to insert: ";
				cin>>sert;

				one.insert(sert);

				cout<<endl<<"The value was inserted."<<endl;

				break;
			case '3':
				cout<<"Enter the value you would like to find: ";
				cin>>sert;

				cout<<endl;
				//if the value is found it will report it was found 
				if(one.find(sert) == NULL)
				{
					cout<<"The value '"<<sert<<"' was not found."<<endl;
				}
				else
				{
					cout<<"The value '"<<sert<<"' was found."<<endl;
				}
	
				break;
			case '4':
				cout<<"Enter the value you would like to remove: ";
                                cin>>sert;

				rem = one.find(sert);

				cout<<endl;
				//if it is not in the tree it cannot be removed
				if(rem == NULL)
				{
					cout<<sert<<" was not found in the tree, cannot remove."<<endl;
				}
				else
				{
					one.removeNode(rem);
					
					cout<<sert<<" was removed from the tree."<<endl;
				}

				break;
			case '5':
				cout<<"Preforming Inorder Traversal."<<endl;
				one.inorderTraversal(visit);				

				break;
			case '6':
				cout<<"Preforming Preorder Traversal."<<endl;
                                one.preorderTraversal(visit);

				break;
			case '7':
				cout<<"Preforming Postorder Traversal."<<endl;
                                one.postorderTraversal(visit);

				break;
			case '8':
				cout<<"Exiting."<<endl;
				return 0;
				break;
			default :
				cout<<"";
		}
		
		cout<<string(5, '\n');
	}

}
/*
*Function: visit
*
*Description: This function decides what to do with the nodes.
*
*Parameters: Node<datat>* passedMain
*
*Return: None
*/
template<class dataT>
void visit(Node<dataT>* passedMain)
{
	cout<<passedMain->value<<endl;
}
