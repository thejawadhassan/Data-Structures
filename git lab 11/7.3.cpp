#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	string n;
};
class BST{
	public:
	Node* root;
	BST()
	{
		root=NULL;
	}
	bool isempty()
	{
		return root==NULL;
	}
	Node* createnode()
	{
	Node* cur=new Node;
	cur->left=NULL;
	cur->right=NULL;
	cout<<"enter key numberand string:";
	cin>>cur->data;
	cin>>cur->n;
	return cur;	
	}
	Node* minkey(Node* m)
	{
		while(m->left!=NULL)
		{
			m=m->left;
		}
		return m;
	}
	Node* maxkey(Node* m)
	{
		while(m->right!=NULL)
		{
			m=m->right;
		}
		return m;
	}
	void insert()
	{
		Node* cur=createnode();
		if(isempty())
        {
        	root=cur;
		}
		 
	    else
	    {
		Node* r=root;
        Node* p;
		while(r!=NULL)
		{
		p=r;
		if(cur->data==r->data)
		{
		 	return;
		}
		if(cur->data>r->data)
		{
		 r=r->right;
        }
		else
		{
		 	r=r->left;
	     }		 	  
	    }
		if(cur->data>p->data)
		{
		 	p->right=cur;
	    }
		else
		{
		 	p->left=cur;
	    }	     	
	    }
	}
	Node* inorder(Node* temp)
	{
		if(temp!=NULL)
		{
		 inorder(temp->left);
		 cout<<temp->data<<" ";
		 inorder(temp->right);	
		}
	}
	Node* preorder(Node* temp)
	{
		if(temp!=NULL)
		{
		 	cout<<temp->data<<" ";
		 preorder(temp->left);
		 preorder(temp->right);	
		}
	}
		Node* postorder(Node* temp)
	{
		if(temp!=NULL)
		{
		 postorder(temp->left);
		 postorder(temp->right);
		 cout<<temp->data<<" ";	
		}
	}
	Node* search(Node* r,int key)
	{
			if(isempty())
			{
				return r;
			}
			if(r->data==key)
			{
				cout<<"found";
				return r;
			}
			else
			{
				if(key>r->data)
				{
				search(r->right,key);
			    } 
				else
				search(r->left,key);
			}
	}
	Node* deletenode(Node* r,int key)
	{
		Node* temp;
		if(isempty())
		{
			return r;
		}
		if(key>r->data)
		{
			r->right=deletenode(r->right,key);
		}
		else if(key<r->data)
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
			r->data=temp->data;
			r->right=deletenode(r->right,temp->data);	
		}
		return r;
	}
	
};
main()
{
	BST b;
	int n;
	while(1)
	{
	cout<<"enter values:";
	cin>>n;
	if(n<0)	
	{break;
	}
	else
	b.insert();
	}
	
	cout<<"\ninoder is:"<<endl;
 	b.inorder(b.root); 
	cout<<"\npreoder is:"<<endl;
 	b.preorder(b.root);
	 cout<<"\npostoder is:"<<endl;
 	b.postorder(b.root); 
 	b.search(b.root,13);
	 	
}