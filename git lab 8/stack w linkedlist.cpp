#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
class Stack{
	Node* head;
	public:
	Stack()
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
	void push(int n)
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
	void pop()
	{
		if(isempty())
	 {
	  	cout<<"stack is empty"<<endl;
	     return;
	 }
	  else
	 {
		Node* p=prevtolastnode();
        if(head->next==NULL)
        {
        	cout<<head->data<<endl;
        	head=NULL;
		}
	   else
        {
		  Node* d=p->next;
		  cout<<d->data<<endl;
		  p->next=NULL;
		  delete d;  
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
Stack s;
while(1)
{cout<<"press 1 to push in stack press 2 to pop press 3 to display press 4 to exit: ";
	cin>>option;
switch(option)	
   {
	case 1:
	cout<<"enter element to push: ";
	cin>>n;
	s.push(n);
	break;
	case 2:
	cout<<"deleted element is: ";
	s.pop();
	break;
	case 3:
	s.display();
	break;
	case 4:
	exit(0);
	default:
	cout<<"invalid input";
     }
}
}
	