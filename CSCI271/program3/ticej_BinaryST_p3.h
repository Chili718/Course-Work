/*
*Program 3: Binary Search Tree Class
*
*Jon Tice
*
*The header/implementation file for the BinaryST class
*
*CSCI271
*
*3/15/2018
*/
#ifndef BinaryST_h
#define BinaryST_h
#include<cstdlib>
#include<iostream>
#include<string.h>
using namespace std;

//struct for the node of a BST with the 
//added frequency counter
template<class dataT>
struct Node
{
	dataT value;
	int frequency;
	Node<dataT>* left;
	Node<dataT>* right;
	
};

template<class dataT>
class BinaryST
{
	public:

		BinaryST();

		~BinaryST();

		void insert(dataT key);

		void removeNode(Node<dataT>* nde);

		void destroyTree(Node<dataT>* startNd);

		void preorderTraversal(void(*func)(Node<dataT>* passed));
		void inorderTraversal(void(*func)(Node<dataT>* passed));
		void postorderTraversal(void(*func)(Node<dataT>* passed));

		Node<dataT>* find(dataT val);

	private:

		Node<dataT>* root;

		void insert(dataT key, Node<dataT>* leaf);

		void preorder(Node<dataT>* passedIn, void(*func)(Node<dataT>* passed));
		void inorder(Node<dataT>* passedIn, void(*func)(Node<dataT>* passed));
		void postorder(Node<dataT>* passedIn, void(*func)(Node<dataT>* passed));
	
		Node<dataT>* find(dataT val, Node<dataT>* nde);

		//helper functions for removeNode
		Node<dataT>* findParent(Node<dataT>* toBeFound);
		Node<dataT>* findMin(Node<dataT>* nde);
};
//Constructor
template<class dataT>
BinaryST<dataT>::BinaryST()
{
	root = NULL;
}
//Function: destroyTree
//
//Description: Recursive function that is called by destructor 
//to delete all nodes
//
//Parameters:Node<dataT>* startNd
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::destroyTree(Node<dataT>* startNd)
{
	if(startNd != NULL)
	{
		destroyTree(startNd->left);
		destroyTree(startNd->right);
		delete startNd;
	}
}
//Destructor 
template<class dataT>
BinaryST<dataT>::~BinaryST()
{
	destroyTree(root);
}

//Function: insert
//
//Description: public insert function that handles NULL root
//
//Parameters:dataT key
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::insert(dataT key)
{
	if(root == NULL)
	{
		
		root = new Node<dataT>();
		strcpy(root->value, key);
		root->left=NULL;
		root->right=NULL;
		root->frequency = 1;
		
	}
	else
	{
		//called the private insert function and passes the private root
		insert(key, root);
	}
}
//Function: insert
//
//Description: private recursive insert function 
//that traverses through loop until proper position is found
//
//Parameters:dataT key, Node<dataT>* leaf
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::insert(dataT key, Node<dataT>* leaf)
{
	//if the value is already in the tree the frequency is increased
	if(strcasecmp(key, leaf->value)==0)
	{
		leaf->frequency++;
		
	}//if the word is earlier in alphabet
        else if(strcasecmp(key, leaf->value)<0)
        {
		
        	if(leaf->left != NULL)
		{
			insert(key, leaf->left);
		}
		else
		{
			leaf->left = new Node<dataT>();
			strcpy(leaf->left->value, key);
			leaf->left->right = NULL;
			leaf->left->left = NULL;
			leaf->left->frequency = 1;
		}        
        }//if the word is later in alphabet
        else if(strcasecmp(key, leaf->value)>0)
        {
        
	        if(leaf->right != NULL)
                {
			insert(key, leaf->right);
                }
                else
                {
			leaf->right = new Node<dataT>();
                        strcpy(leaf->right->value, key);
                        leaf->right->right = NULL;
                        leaf->right->left = NULL;
			leaf->right->frequency = 1;

                }
        }
}
//Function: preorderTraversal
//
//Description: public preorder traverse function
//that uses the private recursive preorder function
//
//Parameters:void(*func)(Node<dataT>* passed)
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::preorderTraversal(void(*func)(Node<dataT>* passed))
{
	preorder(root, *func);
}
//Function: preorder
//
//Description: private recusrive preorder traverse function
//that is passed the function that will decide what to 
//do with the node
//
//Parameters:Node<dataT>* passedIn, void(*func)(Node<dataT>* passed)
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::preorder(Node<dataT>* passedIn, void(*func)(Node<dataT>* passed))
{
	//Preorder: root, left, right
	if(passedIn != NULL)
	{
		(*func)(passedIn);
		preorder(passedIn->left, *func);
		preorder(passedIn->right, *func);
	}
}
//Function: inorderTraversal
//
//Description: public inorder traverse function
//that uses the private recursive inorder function
//
//Parameters:void(*func)(Node<dataT>* passed)
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::inorderTraversal(void(*func)(Node<dataT>* passed))
{
        inorder(root, *func);
}
//Function: inorder
//
//Description: private recusrive inorder traverse function
//that is passed the function that will decide what to
//do with the node
//
//Parameters:Node<dataT>* passedIn, void(*func)(Node<dataT>* passed)
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::inorder(Node<dataT>* passedIn, void(*func)(Node<dataT>* passed))
{
	//Inorder: left, root, right
        if(passedIn != NULL)
        {
                inorder(passedIn->left, *func);
		(*func)(passedIn);
                inorder(passedIn->right, *func);
        }
}
//Function: postorderTraversal
//
//Description: public postorder traverse function
//that uses the private recursive postorder function
//
//Parameters:void(*func)(Node<dataT>* passed)
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::postorderTraversal(void(*func)(Node<dataT>* passed))
{
        postorder(root, *func);
}
//Function: postorder
//
//Description: private recusrive postorder traverse function
//that is passed the function that will decide what to
//do with the node
//
//Parameters:Node<dataT>* passedIn, void(*func)(Node<dataT>* passed)
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::postorder(Node<dataT>* passedIn, void(*func)(Node<dataT>* passed))
{
	//Postorder: left, right, root
        if(passedIn != NULL)
        {
                postorder(passedIn->left, *func);
                postorder(passedIn->right, *func);
		(*func)(passedIn);
        }
}
//Function: removeNode
//
//Description: removes the node passed from the tree and 
//keeps the tree "intact"
//
//Parameters:Node<dataT>* nde
//
//Return Value:None
template<class dataT>
void BinaryST<dataT>::removeNode(Node<dataT>* nde)
{
	Node<dataT>* min;
	Node<dataT>* parent;

	parent = findParent(nde);
	//if both left and right are null then the node is a leaf
	if(nde->left == NULL && nde->right == NULL)
	{
		if(parent->left == nde)
			parent->left = NULL;
		else
			parent->right = NULL;

		delete nde;
	}//only has left child
	else if(nde->right == NULL)
	{

		if(parent->left == nde)
                        parent->left = nde->left;
                else
                        parent->right = nde->left;

		delete nde;
		
	}//only has right child
	else if(nde->left == NULL)
	{
		if(parent->left == nde)
                        parent->left = nde->right;
                else
                        parent->right = nde->right;

                delete nde;
	}//has two children
	else
	{	
		min = findMin(nde->right);
		
		if(min == nde->right)
		{
			if(parent->left == nde)
                       		parent->left = nde->right;
               		else
        	                parent->right = nde->right;

	                delete nde;

		}//if the nodes right child did have two children 
		else
		{
		//using the BST property that the same set of values may be represented
		//as a different BST but we need to find the minimum value of that subtree

			//copy the right subtrees minimum value to the node 
			//we were going to delete so now we must delete the node
			//we copied from
			strcpy(nde->value, min->value);
			nde->frequency = min->frequency;
			//now we remove the node whos value we duplicated to the 
			//node we were going to remove
			removeNode(min);
		}
	}
}
//Function: findParent
//
//Description: finds the parent node of the child passed
//
//Parameters:Node<dataT>* toBeFound
//
//Return Value:Node<dataT>*
template<class dataT>
Node<dataT>* BinaryST<dataT>::findParent(Node<dataT>* toBeFound)
{
	Node<dataT>* parentFound;
	parentFound = NULL;
	Node<dataT>* find;
	find = root;

	while(find != NULL)
	{
		//first returns null if node passed is the root
		if(find == toBeFound)
			return parentFound;
		//parentfound is updated after check because find must contain
		//the node ahead of it to determine when the node passed is found
		parentFound = find;
		//traverses left or right based on the value of toBeFound
		if(strcasecmp(toBeFound->value, find->value)<0)
			find = find->left;
		else
			find = find->right;
	}
	return parentFound;
}
//Function: findMin
//
//Description: finds the minimum value in the right subtree
//from where the node is recursively
//
//Parameters:Node<dataT>* nde
//
//Return Value:Node<dataT>*
template<class dataT>
Node<dataT>* BinaryST<dataT>::findMin(Node<dataT>* nde)
{
	//will initially return if the left child of the node
	//to be deleteds right child is null
	if(nde->left == NULL)
		return nde;
	else
		return findMin(nde->left);
}
//Function: find
//
//Description: private find function that finds the value if it 
//is in the tree using recursion
//
//Parameters:dataT val, Node<dataT>* nde
//
//Return Value:Node<dataT>*
template<class dataT>
Node<dataT>* BinaryST<dataT>::find(dataT val, Node<dataT>* nde)
{
	if(nde == NULL)
	{
		return NULL;
	}
	else if(strcasecmp(val, nde->value)==0)
        {
                return nde;

        }//if the word is earlier in alphabet
        else if(strcasecmp(val, nde->value)<0)
        {
		return find(val, nde->left);

        }//if the word is later in alphabet
        else if(strcasecmp(val, nde->value)>0)
        {
		return find(val, nde->right);
        }	
}
//Function: find
//
//Description: public find function thatstarts the search 
//for the value given in the tree at the root using the private find function
//
//Parameters:dataT val
//
//Return Value:Node<dataT>*
template<class dataT>
Node<dataT>* BinaryST<dataT>::find(dataT val)
{
	return find(val, root);
}
#endif
