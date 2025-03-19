#include <cstdlib>
#include <iostream>

using namespace std; 

//Defines the node.
struct node
{
	int data;
	node* next;
	node* prev;
};


//Function Prototypes
//Passes head pointer
void PrintForward(node* head);
//Passes tail pointer
void PrintReverse(node* tail);

int main(int argc, char** argv)
{
	//Marks front of doubly linked list
	node* head;
	//markess end of doubly linked list
	node* tail;
	node* n;

	//First Node
	//N Poimts to new node
	n = new node;
	//first node holds the number 1
	n->data = 1;
	//node will not point to anything
	n->prev = NULL;
	//head and tail point to same node
	head = n;
	tail = n;

	n = new node;
	n->data = 2;
	//Links node 2 back to first node
	n->prev = tail;
	//links node 1 link to node 2 via the next node
	tail->next = n;
	tail = n; 

	n = new node;
	n->data = 3;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new node;
	n->data = 4;
	n->prev = tail;
	tail->next = n;
	tail = n;
	//last node will not point to anything
	tail->next = NULL;

	PrintForward(head);
	PrintReverse(tail);

	return 0;

}

//Function for printing foward
void PrintForward(node* head)
{
	//points to head
	node* temp = head;

	while (temp != NULL)
	{
		//prints out the node data
		cout << temp->data << " ";
		//procceds to next node
		temp = temp->next;
	}
	cout << endl; 

}

//function for printing data in reverse
void PrintReverse(node* tail)
{
	//points to head
	node* temp = tail;

	while (temp != NULL)
	{
		//prints out the node data
		cout << temp->data << " ";
		//proceceds to next node
		temp = temp->prev;
	}
	cout << endl; 
}
