#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
	Node* prev;
};
class BST{
	public:
		Node* root;
        BST()
        {
         root=NULL;	
		}
		 Node* createnode()
   		 {
		  Node* cur=new Node;
		  cur->next=NULL;
		  cur->prev=NULL; 
		  cout<<"enter value:";
		  cin>>cur->data;
		  return cur;  
	     }
		 void insert()
        {
        	Node* cur= createnode();
			if(root==NULL)
        	{
        		root=cur;
			}
			Node* r=root;
		    Node* p;
        	while(r!=NULL)
        	{
        		p=r;
 			  if(r->data==cur->data)
 			  {
 			   	return;			    	
				} 
			  if(cur->data>r->data)
		  	 {
			     r=r->next;	 			   				
			  } 
 	         else
              {
              	r=r->prev;
			  }
			}
			  if(cur->data>p->data)
			  {
			     p->next=cur;				   	
		      }
			  else
			  p->prev=cur;			  
		}
		 void inorder(Node* temp)
         {
         	if(temp!=NULL)
         	{
         	inorder(temp->prev);
			 cout<<temp->data<<" ";
			inorder(temp->next); 	
			 }
		 }
		   void preorder(Node* temp)
         {
         		if(temp!=NULL)
         	{
         	cout<<temp->data<<" ";
			 preorder(temp->prev);	 
			preorder(temp->next); 	
			 }
		 }
		   void postorder(Node* temp)
         {
       		if(temp!=NULL)
         	{
         	postorder(temp->prev);
			postorder(temp->next); 
			 cout<<temp->data<<" ";	
			 }
		 }
		   Node* minimumkey(Node* m)
		    {
			     	while(m->prev!=NULL)
     	          {
     			      m=m->prev;      	
				   }
			    return m;
					    	 	     	
		  }
	Node* deletenode (Node* r,int key)
	{
		Node* temp;
		if(r==NULL)
        {
        	return r;
	     }
       if(key>r->data)
		{
		 r->next=deletenode(r->next,key);	
		}
		 else if(key<r->data)
		{
		 r->prev=deletenode(r->prev,key);	
		}
		 else
		 {
			if(r->prev==NULL)
			{
			 temp=r->next;
			 delete r;
			 return temp;				 	
		    } 
			else if(r->next==NULL)
			{
			 	temp=r->prev;
				 delete r;
				 return temp;	
		    }   							  	
			 temp=minimumkey(r->next); 
			 r->data=temp->data;
			 r->next=deletenode(r->next,temp->data);
	    }
		 return r;
		   }	    

};
main()
{
	BST b;
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	b.insert();
	cout<<"inorder:";
	b.inorder(b.root);
	cout<<"preorder:";
	b.preorder(b.root);
	cout<<"postorder:";
	b.postorder(b.root);
	b.deletenode(b.root,75);
	cout<<"inorder:";
	b.inorder(b.root);
	
}