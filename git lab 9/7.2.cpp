#include<iostream>
using namespace std;
class Student
{
	public:
	int reg,age;
	string name,city;
	float cgpa;
	
		Student()
		{
			
		}
		Student(int r, string n,string c,int a,float cg)
		{
			reg=r;
			age=a;
	        name=n;
			city=c;
			cgpa=cg;
		}
		void output()
		{
			cout<<reg<<name<<city<<age<<cgpa<<endl;
		}
};
struct Node{
	Student data;
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
	int r,a;
	string n,c;
	float cg;
	cout<<"enter reg no, name, city, age and cgpa: "<<endl;
	cin>>r>>n>>c>>a>>cg;
	Student s(r,n,c,a,cg);
	cur->data=s;
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
			if(head->next==NULL)
		{
			Node* d=head;
			head=tail=NULL;
			delete d;
			}	
		else
		{
			Node* d=tail;
			Node* p=tail->prev;
			p->next=NULL;
			tail=p;
			delete d;
		}
		}
		else
		cout<<"list empty"<<endl;
	 } 
	 Node* searchbyreg(int i)
	 {
		Node* h =head;
		while(h !=NULL)
		{
			if(h->data.reg==i)
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
			Node* d=searchbyreg(id);
			Node* p=d->prev;
			Node* n=d->next;
			p->next=n;
			n->prev=p;
			delete d;
		}
		else
		cout<<"list empty"<<endl;
	}
	void insertatmid(int i)
	{
		Node* p=searchbyreg(i);
		Node* cur=createnode();
		Node* n=p->next;
		p->next=cur;
		cur->prev=p;
		cur->next=n;
		n->prev=cur;
	}
};


main()
{
	int opt,i;
	List l;
	while(1)
	{
	 cout<<"1.insertathead\n2.insertattail\n3.display\n4.delathead\n5.delattail\n6.delbyno\n7.insertatmid\n8.exit\n";
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
	 	cout<<"enter reg no:";
	 	cin>>i;
	 	l.delbyno(i);
	 break;
	 case 7:
	 	cout<<"enter reg no:";
	 	cin>>i;
	 	l.insertatmid(i);
	 	break;
	 	case 8:
	 	exit(0);
	 	default:
	 	cout<<"invalid"<<endl;
}
}
}