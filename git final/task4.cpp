#include<iostream>
using namespace std;
class Books{
	public:
		string title,author;
        float price;
        Books()
        {
		}
        Books(string t,string a,float p)
        {
        title=t;
		author=a;
        price=p;	
		}
};
class Stack{
	private:
	Books arr[100];
	int max=100;
	int top;
	public:
	Stack()
	{
	top=-1;
	}
	void push()
	{
	if(top<max-1)
	 {
	  	cout<<"enter title, author and price:"<<endl;
	  	string t,a;
         float p;
         cin>>t>>a>>p;
		  Books b(t,a,p);
		  top++;
		  arr[top]=b;
	 }
	else
	cout<<"stack full"<<endl;	
	}
	void pop()
	{
	if(top>=0)
	{
		cout<<"popped";
        top--;
		}
		else
		cout<<"stack empty";	
	}
	void find(string f)
	{
		for(int i=0;i<=top;i++)
		{
		 	if(f==arr[i].title)
			{
			 cout<<"found"<<endl;				   	
			 } 
		}
	}
	void del(string f)
	{
	for(int i=0;i<=top;i++)
		{
		 	if(f==arr[i].title)
			{
			 cout<<"deleted"<<endl;	
			 arr[i].price=0;
			 arr[i].title="";
			 arr[i].author="";
			 for(int n=i;n<top;n++)
			 {
			  	arr[n]=arr[n+1];	  	
								}			   	
			 } 
		}	
	}
};
main()
{
Stack s;
string ti;
s.push();
s.push();
s.push();
cout<<"enter book to find:";
cin>>ti;
s.find(ti);	
cout<<"enter book to delete:";
cin>>ti;
s.del(ti);	
}