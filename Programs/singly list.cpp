#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	node(int value,node*address=0)
	{
	  data=value;
	  next=address;
	}
};
class singlylist{
	public:
	node*head;
	node *tail;
	singlylist()
	{
		head=tail=0;
	}
	void insertathead(int value)
	{
		head=new node(value);
		if (tail==0)
		{
			tail=head;
		}
	}
	void insertattail(int value)
	{
		if(tail==0)
		{
			head=tail=new node(value);
		}
		else
		{
		tail->next=new node(value);
		tail=tail->next;
	    }
	}
};
main()
{
	singlylist s;
	s.insertathead(5);
	cout<<s.head<<s.tail<<endl;
	s.insertathead(10);
	cout<<s.head<<s.tail<<endl;
	s.insertattail(20);
	cout<<s.head<<s.tail<<endl;
}
