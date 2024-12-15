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
	bool isempty()
	{
	return head==NULL;
	}
	Node* createnode()
	{
	Node* cur=new Node;
	cur->next=NULL;
	cout<<"enter data: ";
	cin>>cur->data;
	return cur;	
	}
		Node* lastnode()
	{
		Node* h =head;
		while(h->next !=NULL)
		{
			h=h->next;
		}
		return h;
	}
		Node* prevtolast()
	{
		Node* h =head;
		Node* p=head;
		while(h->next !=NULL)
		{
			p=h;
			h=h->next;
		}
		return p;
	}
	void enqueuetail()
	{
	Node* cur=createnode();	
	if(isempty())
	{
		head=cur;
	}

	else
	{
		Node* l=lastnode();
		l->next=cur;
	}
	}
	void enqueuehead()
	{
	Node* cur=createnode();	
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
	void dequeuetail()
	{
		
	
		if(!isempty())
		{
		Node* d=lastnode();
		Node* p=prevtolast();
			cout<<"dequeued: ";
			if(head->next==NULL)
			{
				head=NULL;
				delete d;
			}
				cout<<d->data<<endl;
				p->next=NULL;
				delete d;
			}
		else
		{
			cout<<"queue empty"<<endl;
		}
				
	}
	void dequeuehead()
	{
		if(!isempty())
		{
			cout<<"dequeued: ";
				cout<<head->data<<endl;
				Node* d=head;
				head=head->next;
				delete d;
			}
		else
		{
			cout<<"queue empty"<<endl;
		}
				
	}
	void display()
	{
		cout<<"display is: "<<endl;
		Node* h =head;
		while(h !=NULL)
		{
			cout<<h->data<<endl;
			h=h->next;
		}
		
	}
};
main()
{
	int opt;
	Queue q;
	while(1)
	{
	 cout<<"1.enqueue at head\n2.enqueue at tail\n3.dequeue at head\n4.dequeue at tail\n5.display\n6.exit\n";
	 cin>>opt;
	 switch(opt)
	 {
	 case 1:
	q.enqueuehead();
	 break;
	 case 2:
	 	q.enqueuetail();
	 	break;
	 	case 3:
	 	q.dequeuehead();
	 break;
	 case 4:
	 	q.dequeuetail();
	 break;
	 case 5:
	 	q.display();
	 break;
	 case 6:
	 	exit(0);
	 	default:
	 		cout<<"invalid"<<endl;
}
}
}