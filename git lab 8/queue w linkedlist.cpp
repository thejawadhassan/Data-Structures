#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class Queue{
	Node* head;
	public:
	Queue()
	{
	head=NULL;	
	}
	Node* createnode(int n)
	{
	 Node* cur=new Node;
	 cur->data=n;
	 cur->next=NULL;
	 return cur;	
	}
	Node* lastnode()
	{
		Node* h=head;
		while(h->next!=NULL)
		{
		 h=h->next;					 						
		}
		 return h;
	}
	void enqueue(int n)
	{
		Node*cur =createnode(n);
	   if(isempty())
	      {
		    head=cur;    	
		  }
       else
       {
       	Node*last=lastnode();
       	last->next=cur;
	   }			 
	}
	Node* prevtolastnode()
	{
			Node* h=head;
            Node* p =head;
		while(h->next!=NULL)
		{
		 p=h;	
		 h=h->next;					 						
		}
		 return p;
	}
	void dequeue()
	{
		if(isempty())
	 {
	  	cout<<"stack is empty"<<endl;
	     return;
	 }
	  else
	 {
        if(head->next==NULL)
        {
        	cout<<head->data<<endl;
        	head=NULL;
		}
	   else
        {
          cout<<head->data<<endl;	
		  Node* temp=head;
		  head=temp->next;
		  temp->next=NULL;
		  delete temp;  
	     }
	}
    }
	bool isempty()
	{
		return head==NULL;
	}
	void display()
	{
		if(!isempty())
		{Node* h=head;
        cout<<"display of all stack is: "<<endl;
		while(h!=NULL)
		{
 	     cout<<h->data<<endl;
		 h=h->next;					 						
		}
	    }
	    else
		cout<<"stack is empty"<<endl;    
	}
	
};
main()
{
int option,n;
Queue q;
while(1)
{cout<<"press 1 to enqueue in queue press 2 to dequeue press 3 to display press 4 to exit: ";
	cin>>option;
switch(option)	
   {
	case 1:
	cout<<"enter element to enqueue: ";
	cin>>n;
	q.enqueue(n);
	break;
	case 2:
	cout<<"deleted element is: ";
	q.dequeue();
	break;
	case 3:
	q.display();
	break;
	case 4:
	exit(0);
	default:
	cout<<"invalid input";
     }
}
}
	