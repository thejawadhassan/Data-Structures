#include<iostream>
#include<cstring>
using namespace std;

struct Node{
	int roll;
	string name;
	Node* next;
};
struct Link{
	Node* head;
	void get()
	{
		head=NULL;
	}
	void insertathead()
	{
	 Node* cur= createnode();
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
	void insertattail()
	{
		Node* cur= createnode();
	 if(isempty())
	 {
	 	head=cur;
	 }
	 else
	 {
		Node* last=lastnode(); 
		last->next=cur;
	}	
	}
	bool isempty()
	{
	 return head==NULL;	
	}
	Node* createnode()
	{
	 Node* cur= new Node;
	 readnode(cur);
	 cur->next=NULL;
	 return cur;	
	}
	void readnode(Node* cur)
	{
		cout<<"enter roll: ";
		cin>>cur->roll;
		cout<<"enter name: ";
		cin>>cur->name;
	}
	void display()
	{
		if(!isempty())
		{
		 Node* h=head;
	 while(h!=NULL)
	 {
	  cout<<h->name<<" "<<h->roll<<endl;
	  h=h->next;	
	 }		
		}
		else
		cout<<"empty list"<<endl;
	
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
	Node* searchprevbyroll(int r)
	{
		Node* h=head;
		Node* p=head;
		while(h!=NULL)
		{
			if(h->roll==r)
			{
				return p;
			}
			p=h;
			h=h->next;
		}
		cout<<"roll no. not found!"<<endl;
	
	}
	Node* prevtolast()
	{
		Node* h=head;
		Node* p=head;
		while(h->next!=NULL)
		{
			p=h;
			h=h->next;
		}
		return p;
	}
	void delathead()
	{
	 if(!isempty())
	 {
	  	 Node* d=head;
		 head=head->next;
		 delete d;
		 }	
		 else
		 cout<<"link list is empty"<<endl;
	}
	void delattail()
	{
	   if(!isempty())
	    {
	    	
	  	 Node* p=prevtolast();
	  	 if(head->next==NULL)
	  	 {
	  	 	head=NULL;
		   }
		else{
		
	  	 Node* d=p->next;
	  	 p->next=NULL;
	  	 delete d;
	     }
		 }	
		 else
		 cout<<"link list is empty"<<endl;	
	}
	void insertafterroll(int r)
	{
		Node* cur=createnode();
		Node* p=searchprevbyroll(r);
		Node* temp=p->next;
		Node* a=temp->next;
		temp->next=cur;
		cur->next=a;
	}
	void insertbeforeroll(int r)
	{
		Node* cur=createnode();
		Node* p=searchprevbyroll(r);
		Node* temp=p->next;
		p->next=cur;
		cur->next=temp;	
	}
	void delbyroll(int r)
	{
		Node* p=searchprevbyroll(r);
		Node* d=p->next;
		p->next=d->next;
		delete d;	
	}
	
	void delbyname(string n)
	{
		Node* p=searchprevbyname(n);
		Node* d=p->next;
		p->next=d->next;
		delete d;	
	}
	Node* searchprevbyname(string n)
	{
		Node* h=head;
		Node* p=head;
		while(h!=NULL)
		{
			if(h->name==n)
			{
				return p;
			}
			p=h;
			h=h->next;
		}
		cout<<"name not found!"<<endl;
		return NULL;
	}
	void insertaftername(string n)
	{
		Node* cur=createnode();
		Node* p=searchprevbyname(n);
		Node* a=p->next;
		Node* temp=a->next;
		a->next=cur;
		cur->next=temp;	
    }
	
};
main()
{
	int n,opt;
	string na;
	Link l;
	l.get();
	while(1)
	{
	 cout<<"1.insertathead\n2.insertattail\n3.display\n4.delathead\n5.delattail\n6.insertafterroll\n7.insertbeforeroll\n8.delbyroll\n9.delbyname\n10.insertaftername\n11.exit\n";
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
	 	cout<<"enter roll:";
	 	cin>>n;
	 l.insertafterroll(n);
	 break;
	 case 7:
	 	cout<<"enter roll:";
	 	cin>>n;
	 l.insertbeforeroll(n);
	 break;	
	 case 8:
	 	cout<<"enter roll:";
	 	cin>>n;
	 l.delbyroll(n);
	 break;	
	 case 9:
	 	cout<<"enter name:";
	 	cin>>na;
	 l.delbyname(na);
	 break;	
	 case 10:
	 	cout<<"enter name:";
	 	cin>>na;
	 l.insertaftername(na);
	 break;	
	 case 11:
	 exit(0);
	 default:
	 cout<<"wrong value entered"<<endl;	
	 }	
			
	}
}