#include<iostream>
using namespace std;
struct Node{
	int roll;
	string name;
	int prior;
	Node* next;
};
class Link{
	Node* head;
	public:
		Link()
		{
			head =NULL;
		}
		Node* createnode()
		{
		 Node* cur=new Node;
		 cur->next=NULL;
		 readnode(cur);
		 return cur; 	
		}
		bool isempty()
		{
			return head==NULL;
		}
		void readnode(Node* cur)
		{
			cout<<"enter name, roll, priority:"<<endl;
			cin>>cur->name>>cur->roll>>cur->prior;
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
		void enqueue()
		{
			Node* cur= createnode();
			Node* p= searchprevbyprior(cur->prior);
			if(isempty())
			{
				head=cur;
			}
			else
			{
				if(p==head)
				{
					cur->next=head;
					head=cur;
					return;
				}
				if(p==NULL)
				{
					Node* l=lastnode();
					l->next=cur;
					return;
				}
				//in between
				Node* temp=p->next;
				p->next=cur;
				cur->next=temp;
				
			}
		}
		Node* searchprevbyprior(int prior)
		{
			Node* h =head;
			Node* p=head; 
			while(h!=NULL)
			{
				if(h->prior<prior)
				{
					return p;
				}
				p=h;
				h=h->next;
			}
			return NULL;
		}
		void dequeue()
		
		{
			if(!isempty())
			{
			Node* d =head;
			cout<<d->prior<<" "<<d->name<<endl;
			head=d->next;
			d->next=NULL;
			delete d;
		   }
			else
			cout<<"list is empty"<<endl;
			
		}
		void display()
		{
			Node* h =head;
			while(h!= NULL)
			{
				cout<<h->prior<<" "<<h->name<<endl;
				h=h->next;
			}
		}
};
main()
{
	Link l;

	int opt;
	while(1)
	{
	 cout<<"1.enqueue\n2.dequeue\n3.display\n4.exit\n";
	 cin>>opt;
	 switch(opt)
	 {
	 case 1:
		l.enqueue();
	 break;
	 case 2:
	 	l.dequeue();
	 break;
	 case 3:
	 	l.display();
	 break;
	 case 4:
	 exit(0);
	 default:
	 cout<<"wrong value entered"<<endl;	
	 }	
			
	}
}