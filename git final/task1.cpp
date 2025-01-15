#include<iostream>
using namespace std;
struct Student{
		int reg;
		string name;
        float cgpa;
        Student* right;
        Student* left;
        Student()
        {
        	
		}
		 void input()
         {
         	cin>>reg>>name>>cgpa;
		 }
         void output()
         {
         	cout<<reg<<name<<cgpa;
		 }
};
class BST{
	public:
	Student* root;
	BST()
	{
	root=NULL;
	}
	Student* createnode()
	{
	Student* cur= new Student;
	cout<<"enter reg,name,cgpa"<<endl;
	cin>>cur->reg>>cur->name>>cur->cgpa;
	cur->right=NULL;
	cur->left=NULL; 
	return cur;	
	}
	void insert()
	{
	 Student* cur=createnode();
	  Student* r=root;
	    Student* p;
	  if(root==NULL)
	    {
    	root=cur;
		}
	   else
	      {
		  while(r!=NULL)
		  {p=r;
		   if(r==NULL)
		   {return;
				 } 
			if(cur->reg>r->reg)
			{
			 	r=r->right;		   	
				 }
			else
			r=r->left; 	
		  }      
		   if(cur->reg>p->reg)
		   {p->right=cur;
					}     	
		     else
			 p->left=cur;   	
		  }
    }
    void preorder(Student* temp)
    {
    if(temp!=NULL)	
    {
    cout<<temp->reg<<" ";
	preorder(temp->left);
	preorder(temp->right);
	}
	}
	void inorder(Student* temp)
    {
     if(temp!=NULL)	
    {
	inorder(temp->left);
	cout<<temp->reg<<" ";
	inorder(temp->right);	
	}	
	}
	void postorder(Student* temp)
    {
     if(temp!=NULL)	
    {
	postorder(temp->left);
	postorder(temp->right);	
	cout<<temp->reg<<" ";
	}	
	}
	
};
main()
{
BST b;
b.insert();
b.insert();
b.insert();
b.insert();
cout<<"inorder:"<<endl;
b.inorder(b.root);
cout<<"\npreorder:"<<endl;
b.preorder(b.root);
cout<<"\npostorder:"<<endl;
b.postorder(b.root);
}