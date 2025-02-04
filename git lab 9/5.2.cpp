#include<iostream>
using namespace std;
class Person
{
	public:
	int id;
	string name;
	int age;
		Person()
		{
			
		}
		Person(int i, string n,int a)
		{
			id=i;
	        name=n;
			age=a;
		}
		void output()
		{
			cout<<id<<name<<age<<endl;
		}
};
struct Node{
	Person data;
	Node* next;
	Node* prev;
};

class List{
	Node* head;	
	Node* tail;
	public:
	List()
	{
		head=tail=NULL;
	}
	bool isempty()
	{
	return head==NULL;
	}
	Node* createnode()
	{
	Node* cur=new Node;
	cur->next=NULL;
	cur->prev=NULL;
	cout<<"enter id,name and age: "<<endl;
	int i,a;
	string n;
	cin>>i>>n>>a;
	Person o(i,n,a);
	cur->data=o;
	return cur;	
	}
	void display()
	{
		cout<<"display is: "<<endl;
		Node* h =head;
		while(h !=NULL)
		{
			h->data.output();
			h=h->next;
		}	
	}
	void insertathead()
	{
		Node* cur=createnode();
		if(isempty())
		{
			head=tail=cur;
		}
		else
		{
			cur->next=head;
			head->prev=cur;
			head=cur;
		}
	}
	void insertattail()
	{
		Node* cur=createnode();
		if(isempty())
		{
			head=tail=cur;
		}
		else
		{
			tail->next=cur;
			cur->prev=tail;
			tail=cur;
		}
	}
	void delathead()
	{
		if(!isempty())
		{
			Node* d=head;
		if(d->next==NULL)
		{
			head=tail=NULL;
			delete d;
			}	
		else
		{
			head=d->next;
			head->prev=NULL;
			delete d;
		}
		}
		else
		cout<<"list empty"<<endl;
	}
	void delattail()
	{
			if(!isempty())
		{
			Node* d=tail;
			if(d->next==NULL)
		{
			head=tail=NULL;
			delete d;
			}	
		else
		{
			Node* p=tail->prev;
			p->next=NULL;
			tail=p;
			delete d;
		}
		}
		else
		cout<<"list empty"<<endl;
	 } 
	 Node* searchbyid(int i)
	 {
		Node* h =head;
		while(h !=NULL)
		{
			if(h->data.id==i)
			{
				return h;
			}
			h=h->next;
		}	
	 }
	 
	void delbyno(int id)
	{
			if(!isempty())
		{
			Node* d=searchbyid(id);
			Node* p=d->prev;
			Node* n=d->next;
			p->next=n;
			n->prev=p;
			delete d;
		}
		else
		cout<<"list empty"<<endl;
	}
	
};


main()
{
	int opt,i;
	List l;
	while(1)
	{
	 cout<<"1.insertathead\n2.insertattail\n3.display\n4.delathead\n5.delattail\n6.delbyno\n7.exit\n";
	 cin>>opt;
	 switch(opt)
	 {
	 	case 1:
	l.insertathead();
	 break;
	 case 2:
	 	l.insertattail();
	 break;
	 case 3:
	 	l.display();
	 break;
	 case 4:
	l.delathead();
	 break;
	 case 5:
	 	l.delattail();
	 break;
	 case 6:
	 	cout<<"enter id:";
	 	cin>>i;
	 	l.delbyno(i);
	 break;
	 case 7:
	 	exit(0);
	 	default:
	 	cout<<"invalid"<<endl;
}
}
}