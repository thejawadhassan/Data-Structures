#include<iostream>
using namespace std;
struct Person
{
	int id,age;
	string name;
	Person* right;
	Person* left;
	Person()
	{	
	}
    void input()
    {
    	cin>>id>>age>>name;
	}
	void output()
	{
		cout<<id<<name<<age;
	}
};
class BST{
	public:
	Person* root;
	BST()
	{
		root=NULL;
	}
	bool isempty()
	{
		return root==NULL;
	}
	Person* createnode()
	{
	Person* cur=new Person;
	cur->left=NULL;
	cur->right=NULL;
	cout<<"enter id number:";
	cin>>cur->id;
	return cur;	
	}
	Person* minkey(Person* m)
	{
		while(m->left!=NULL)
		{
			m=m->left;
		}
		return m;
	}
	Person* maxkey(Person* m)
	{
		while(m->right!=NULL)
		{
			m=m->right;
		}
		return m;
	}
	void insert()
	{
		Person* cur=createnode();
		if(isempty())
        {
        	root=cur;
		}
		 
	    else
	    {
		Person* r=root;
        Person* p;
		while(r!=NULL)
		{
		p=r;
		if(cur->id==r->id)
		{
		 	return;
		}
		if(cur->id>r->id)
		{
		 r=r->right;
        }
		else
		{
		 	r=r->left;
	     }		 	  
	    }
		if(cur->id>p->id)
		{
		 	p->right=cur;
	    }
		else
		{
		 	p->left=cur;
	    }	     	
	    }
	}
	Person* inorder(Person* temp)
	{
		if(temp!=NULL)
		{
		 inorder(temp->left);
		 cout<<temp->id<<" ";
		 inorder(temp->right);	
		}
	}
Person* preorder(Person* temp)
	{
		if(temp!=NULL)
		{
		 	cout<<temp->id<<" ";
		 preorder(temp->left);
		 preorder(temp->right);	
		}
	}
		Person* postorder(Person* temp)
	{
		if(temp!=NULL)
		{
		 preorder(temp->left);
		 preorder(temp->right);
		 cout<<temp->id<<" ";	
		}
	}
	Person* search(Person* r,int key)
	{
			if(isempty())
			{
				return r;
			}
			if(r->id==key)
			{
				return r;
			}
			else
			{
				if(key>r->id)
				{
				search(r->right,key);
			    } 
				else
				search(r->left,key);
			}
	}
	Person* deletenode(Person* r,int key)
	{
		Person* temp;
		if(isempty())
		{
			return r;
		}
		if(key>r->id)
		{
			r->right=deletenode(r->right,key);
		}
		else if(key<r->id)
		{
			r->left=deletenode(r->left,key);
		}
		else{
			if(r->right==NULL)
			{
				temp=r->left;
				delete r;
				return temp;
			}
			else if(r->left==NULL)
			{
				temp=r->right;
				delete r;
				return temp;
			}
			temp=minkey(r->right);
			r->id=temp->id;
			r->right=deletenode(r->right,temp->id);	
		}
		return r;
	}
	
};
class List{
	Person* head;
	public:
	List()
	{
	head==NULL;	
	}
	Person* createnodee()
	{
	Person* cur=new Person;
	cur->left=NULL;
	cur->right=NULL;
	cout<<"enter id number:";
	cin>>cur->id;
	return cur;	
	}
	void insertt()
	{
	Person* cur =createnodee();
	if(head==NULL)
	{
		head=cur;
		}	
		else
		cur->right=head;
		head=cur;
	}
	void searchh(int key)
	{
		Person* h=head;
		while(h!=NULL)
		{if(h->id==key)
		cout<<"found";
		h=h->right;
		}
	}
	void del(int key)
	{
		Person* h=head;
		Person* p;
		while(h!=NULL)
		
		{
		p=h;
		if(h->id==key)
		{
			p->right=h->right;
			delete h;
		}
		h=h->right;
		}
	}
};
main()
{
	BST b;
	List l;
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	cout<<"\ninoder is:"<<endl;
 	b.inorder(b.root); 
	cout<<"\npreoder is:"<<endl;
 	b.preorder(b.root);
	 cout<<"\npostoder is:"<<endl;
 	b.postorder(b.root); 	
}