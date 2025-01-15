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
	node*tail;
	singlylist()
	{
		head=tail=0;
	}
	void insertathead(int value)
	{
		head=new node(value,head);
		if (tail==0)
		{
			tail=head;
		}
	}
	void insertattail(int value)
	{
		tail->next=new node(value);
		tail=tail->next;
		if (tail==0)
		{
			head=tail=new node(value);
		}
		
	}
	void insertatmid(node*prev_address,int value)
	{
		node*new_node=new node(value,prev_address->next);
		prev_address->next=new_node;
	}
};
main()
{

singlylist s;
s.insertathead(5);
s.insertattail(15);
s.insertatmid(0,10);
}
