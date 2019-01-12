//Program to demonstratebthe use of single-linked list
#include <iostream>
using namespace std;
class Node
{
	public:
	//data
	int data;
	//pointer to the next node
	Node *next;
	//construct that makes the pointer to null
	Node()
	{
		next=NULL;
	}
};
class LinkedList
{
	//head+circles inside linked with each other
	public:
	//head->node type ptr
	Node *head;
	Node *tail;
	//construct
	LinkedList()
	{
		head=NULL;
		tail=NULL;
	}
	//circles inside linked with each other
	//rules how circles will be linked
	//insert
	void insert(int value)
	{
		//if 1st node is added
		Node *temp = new Node;
		//insert value in the node
		temp->data=value;
		//1st node only
		if(head==NULL)
		{
		   head=temp;
	    }
		//any other node only
	
		else
		{
	       tail->next=temp;
	    }
	    tail=temp;
	}
	//inserting a node
	void insertAt(int pos, int value)
	{
	    int i=0;
	   	Node *current=head;
		while (current!=NULL)
		{
		    i++;
		    current=current->next;
		}
		//if position of entry exceeds number of elements in list
		if(pos>i)
		{
		    cout<<"Linked List does not have that many elements"<<endl;
		}
		else
		{
	       //for inserting link at 1st position
	       if(pos==1)
	       {
	           Node *temp=new Node;
	           temp->data=value;
	           temp->next=head;
	           head=temp;
	       }
		   //other than 1st position reach the place before the position
	   	   else
	       {
		       Node *current=head;
	           int i=1;
		       while(i<pos-1)
		       {
		          i++;
		          current=current->next;
		       }
		       //create a node
		       Node *temp=new Node;
		       temp->data=value;
		       //moving pointers like magic!!;-P
		       temp->next=current->next;
		       current->next=temp;
	       }
		}
	}
	//deletion of last element
	void deleteLast()
	{
		//store the tail in temp
		Node *temp=tail;
		//before tail has to point to null
		Node *current=head;
		while (current->next!=tail)
		{
	        current=current->next;
		}
		current->next=NULL;
		//update tail
		tail=current;
		//delete temp
		delete temp;
	}
	//delete node from asked position
	void deleteAt(int pos)
	{
	    Node *temp= new Node;
	    temp=head;
	    if(pos==1)
	    {
	        head=temp->next;
	        delete temp;
	    }
	    else
	    {
	        int i=1;
		    while(i<pos-1 && temp!=NULL)
		    {
		        temp=temp->next;
		        i++;
		    }
		    Node *next=temp->next->next;
		    //delete temp
		    delete temp->next;
		    temp->next=next;
		
	    }
	}
	//to count the number of items
	void countItems()
	{
	    int i=0;
	   	Node *current=head;
		while (current!=NULL)
		{
		    i++;
		    current=current->next;
		}
		cout<<"The number of items is "<<i<<endl;
	}
	//display of output
	void display()
	{
		Node *current=head;
		while (current!=NULL)
		{
			cout<<current->data<<"->";
	        current=current->next;
		}
		cout<<"NULL"<<endl;
	}
};
int main()
{
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
	l1.display();
	l1.countItems();
	l1.deleteLast();
	l1.display();
	l1.deleteAt(1);
	l1.display();
    l1.insertAt(2,2);
	l1.display();
	l1.insert(11);
	l1.display();
	l1.insertAt(1,99);
	l1.display();
	
    //return statement
	return 0;
}