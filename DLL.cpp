//Implementation of Doubly Linked List using C++
//library
#include <iostream>
//using namespace std;

using namespace std;
class Node{
    public:
    //Data
    int data;
    //Pointer to the suv Node and asmo Node
    Node *suv;
    Node *asmo;
    //Constructor to make suv and asmo to null
    Node()
    {
        suv=NULL;
        asmo=NULL;
    }
};
class LinkedList{
    public:

    //Head-> circle type suv
    Node *head;
    Node *tail;
    //Constructor
    LinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    //Circle inside linked with each other
    //Rules how circle will be linked
    //Insertion
    void insert(int value)
    {
        //1st Node is added
        Node *temp=new Node();
        //Insert data in node
        temp->data=value;
        if(head==NULL)
        {
            //1st node only
                head=temp;
        }
        else
        {
        //Any other node
        temp->asmo=tail;
        tail->suv=temp;
        }
        
            tail=temp;
        
    }
    //Insert at 
    void InsertAt(int pos,int data)
    {
         //Count numbers
        int count=0;
        Node *current=head;
        for(int i=0;current!=NULL;i++)
        {
            count++;
            current=current->suv;
        }
        //Put conditionon pos
        if(pos>0 && pos<=count)
        {
            //If position is 1st position
            if(pos==1)
            {
                Node *current=head;
                Node *bhai=new Node();
                bhai->data=data;
                bhai->suv=current;
                current->asmo=bhai;
                head=bhai;
            }
            else
            {
                //Reach the place before pos
                Node *current=head;
                int i=1;
                while(i<pos-1)
                {
                   i++;
                   current=current->suv;
                }
                //Create the node
                Node *bhai=new Node();
                bhai->data=data;
                bhai->suv=current->suv;
                current->suv=bhai;
                bhai->suv->asmo=bhai;
                bhai->asmo=current;
            }
        }
        else
        {
            cout<<pos<<" is invalid position"<<endl;
        }
    }
    
    //Deletion of last element
    void del()
    {
        //store tail in temp
        Node *temp=tail;
        //before tail has to point to NULL
         Node *current=head;
        while(current->suv!=tail)
        {
            current=current->suv;
        }
        current->suv=NULL;
        temp->asmo=NULL;
        //update tail
        tail=current;
        //delete temp
        delete temp;
        
    }
    //count items
    int countItems()
    {
        Node *current=head;
        int length=0;
        while(current!=NULL)
        {
            length++;
            current=current->suv;
        }
        return length;
    }
    //Delete at position
    void deleteAt(int pos)
    {
        //Count numbers
        int count=0;
        Node *current=head;
        for(int i=0;current!=NULL;i++)
        {
            count++;
            current=current->suv;
        }
        //Put condition for position
        if(pos>0 && pos<=count)
        {
            //If pos is 1st position
            if(pos==1)
            {
                Node *x=head;
                head=head->suv;
                x->suv=NULL;
                head->asmo=NULL;
                delete x;
            }
            else
            {
                //Reach the place before pos
                Node *current=head;
                int i=1;
                while(i<pos-1)
                {
                   i++;
                   current=current->suv;
                }
                //copy the node to be deleted
                Node *temp=current->suv;
                current->suv->suv->asmo=current;
                current->suv=current->suv->suv;
                temp->suv=NULL;
                temp->asmo=NULL;
                delete temp;
            }
        }
        else
        {
            cout<<pos<<" is invalid position"<<endl;
        }
    }
    //Display
    
    void display()
    {
        Node *current=head;
        Node *last;
        while(current!=NULL)
        {
            cout<<current->data<<"->";
            last=current;
            current=current->suv;//Move to next node
            
        }
        cout<<"NULL"<<endl;
        cout<<endl;
        cout << "Print in Reverse order : "<<endl;
        while(last!=NULL)
        {
            cout <<last->data<< "->";
            // Move backwards 
            last = last->asmo;
        }
        cout <<"NULL"<< endl;
    }

};

int main()
{
    //Object of the class
    LinkedList l1;
    //Enter values
    for(int i=1;i<11;i++)
    {
        l1.insert(i);
    }
    //output
    l1.display();
    cout<<"The number of items before deletion="<<l1.countItems()<<endl;
    cout<<endl;
    
    l1.del();//use of delete
    l1.display();
    cout<<"The number of items after deletion="<<l1.countItems()<<endl;
    cout<<endl;
    
    l1.InsertAt(1,16);
    l1.display();
    cout<<"The number of items after insertion at position 1="<<l1.countItems()<<endl;
    cout<<endl; 
    
    l1.InsertAt(-2,13);
    l1.display();
    cout<<endl;
    
    l1.InsertAt(55,42);
    l1.display();
    cout<<endl;
    
    cout<<"Display after insertion at particular position 3::"<<endl;
    l1.InsertAt(3,17);
    l1.display();
    cout<<"The number of items after insertion at position="<<l1.countItems()<<endl;
    cout<<endl;

    l1.deleteAt(1);
    l1.display();
    cout<<"The number of items after delete at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    l1.deleteAt(-1);//use of deleteAt
    l1.display();
    cout<<"The no. of items after delete ="<<l1.countItems()<<endl;
    cout<<endl;
    
    l1.deleteAt(89);//use of deleteAt
    l1.display();
    cout<<"The no. of items after delete at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    cout<<"Displaying after deletion at particular position 4::"<<endl;
    l1.deleteAt(4);//use of deleteAt
    l1.display();
    cout<<"The no. of items after delete at position="<<l1.countItems()<<endl;
    cout<<endl;
    
    return 0;
}
