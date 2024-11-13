#include<iostream>
using namespace std;
struct node{
	int data;
	node*next;
};
class list{
	node*head;
	public:
	list()
	{
		head=NULL;
	}
	~list()
	{
		while(head!=NULL)
		{
		 	node*l=lastnode();
		}
		delete head;
			   
	}
	node*createnode(int val)
	{
	node*cur= new node;
	cur->data=val;
	cur->next=NULL;
	return cur;
	}
	void insertathead(node*cur)
	{
		if(isempty())
	 {
	   head=cur;
	 }
	  else
	    {
    	  cur->next=head;
  	      head=cur;
		}
	}
	node* lastnode()
	{
		node*h=head;
		while(h->next!=NULL)
	     {
     	  h=h->next;
		 }
		   return h;
	}
	void insertattail(node*cur)
	{
		if(isempty())
	 {
	   head=cur;
	 }
	  else
	    {
    	  node*last=lastnode();
    	    last->next=cur;
		}
	}
	bool isempty()
	{
	 
	  return head==NULL;
	  
	}
	void display()
	{
		node*h=head;
		while(h!=NULL)
		 {
			cout<<"value is: "<<h->data<<endl;	
			h=h->next;	   	   	     	
		 }
		
	}
	void delatfront()
	{
		
	}
	void delattail()
	{
		
	}
	
};

main()
{
list l;	
node*cur;
cur=l.createnode(10);
l.insertathead(cur);
cur=l.createnode(20);
l.insertattail(cur);
cout<<l.isempty()<<endl;
l.display();
l.delatfront();
l.delattail();	
	
}