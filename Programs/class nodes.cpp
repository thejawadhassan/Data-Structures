#include<iostream>
using namespace std;
class node{
	public:
		int data;
	    node *next;
	node(int value,node *address=0)
	{
		data =value;
		next=address;
	}
};
main()

{
	node*p=new node(5);
	p->next=new node(10);
	p->next->next=new node(15);
	cout<<p->next->next->data;
	
}
