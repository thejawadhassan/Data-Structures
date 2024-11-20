#include<iostream>
#include<cstring>
using namespace std;

struct Node{
	int roll;
	string name;
	Node* next;
};
class Link{
	Node* head;
	public:
	Link()
	{
		head=NULL;
	}
	void insertathead()
	{
	 Node* cur= createnode();
	 if(isempty())
	 {
	 	head=cur;
	 	cur->next=head;
	 }
	 else
	 {
	 	cur->next=head;
	 	head=cur;
	 	Node* l=lastnode();
	 	l->next=head;
	 }
		
	}
	void insertattail()
	{
		Node* cur= createnode();
	 if(isempty())
	 {
	 	head=cur;
	 	cur->next=head;
	 }
	 else
	 {
		Node* last=lastnode(); 
		last->next=cur;
		cur->next=head;
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
		 if(h==head)
		 {
		 	cout<<h->name<<" "<<h->roll<<endl;
		 	h=h->next;
		 }
	 while(h!=head)
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
	 while(h->next!=head)
	 {
	 	h=h->next;
	}
	return h;	
	}
	Node* searchprevbyroll(int r)
	{
		Node* h=head;
		Node* p=head;
		if(h->roll==r)
		{
			return p;
		}
		else
		{
		h=h->next;
		while(h!=head)
		{
			if(h->roll==r)
			{
				return p;
			}
			p=h;
			h=h->next;
		}
	   }
		cout<<"roll no. not found!"<<endl;
	
	}
	Node* prevtolast()
	{
		Node* h=head;
		Node* p=head;
		
		while(h->next!=head)
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
		 head=d->next;
		 d->next=NULL;
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
	  	 if(p->next==head)
	  	 {
	  	        Node* d=p;
			   head=NULL;
			   d->next=NULL;
			   delete d;
		   }
		else{
		
	  	 Node* d=p->next;
	  	 p->next=head;
	  	 d->next=NULL;
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
		Node* a=p->next;
		
		Node* temp=a->next;
		a->next=cur;
		cur->next=temp;
	}
	void insertbeforeroll(int r)
	{
		Node* cur=createnode();
		Node* p=searchprevbyroll(r);
		Node* a=p->next;
		p->next=cur;
		cur->next=a;	
	}
	void delbyroll(int r)
	{
		Node* p=searchprevbyroll(r);
		Node* d=p->next;
		p->next=d->next;
		d->next=NULL;
		delete d;	
	}
	
	void delbyname(string n)
	{
		Node* p=searchprevbyname(n);
		Node* d=p->next;
		p->next=d->next;
		d->next=NULL;
		delete d;	
	}
	Node* searchprevbyname(string n)
	{
		Node* h=head;
		Node* p=head;
		if(h->name==n)
		{
			return p;
		}
		else
		{
			h=h->next;
		
		while(h!=head)
		{
			if(h->name==n)
			{
				return p;
			}
			p=h;
			h=h->next;
		}
	    }
	
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