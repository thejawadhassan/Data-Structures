#include<iostream>
using namespace std;
class Book{
	string title;
	string author;
	float price;
	public:
	 Book()
	  {
	    	
	  }
      Book(string t,string a,float p)
	  {
    title=t;
	author=a;
	price=p;	
	  }
      void output()
      {
  	  cout<<title<<" "<<author<<" "<<price<<endl;
	  }
	
};
class Stack
 {
	int top;
	Book arr[10];
	int max=10;
	public:
	Stack()
	{
      top=-1;
	}
	bool isfull()
	{
	  if(top<max-1)
	  {
	    	return 0;
		  }	
		  else
		  return 1; 
	}
	bool isempty()
	{
	  if(top>=0)
	  {
	    	return 0;
		  }	
		  else
		  return 1; 	
	}
	void push()
	{
		string t,a;
		float p;
		if(!isfull())
		 {
			cout<<"enter book title, author and price: "<<endl;
			cin>>t>>a>>p;
			top++;
			Book b(t,a,p);
			arr[top]=b;		  			  				  	
		 }
		   else
		   cout<<"array is full"<<endl; 
	}
	void pop()
	{
	if(!isempty())
	{
		cout<<"popped/deleted book is: ";
		arr[top].output();
        
        top--;
		}
	 else
	 {
	  	cout<<"array empty"<<endl;
		 }	
	}
	void display()
	{
		if(!isempty())
	{
		cout<<"displayed books are: ";
		for(int i=0;i<=top;i++)
		{
		 	arr[i].output();
		}
		}
	 else
	 {
	  	cout<<"array empty"<<endl;
		 }	
	}
};
main()
{
	Stack s;
	int opt;
while(1)
{
	cout<<"1.Push\n2.Pop\n3.Display\n4.exit\nEnter: ";
	cin>>opt;
	switch(opt)
	{
		case 1:
 	    s.push();
 		break;
        case 2:
 	    s.pop();
 		break;
        case 3:
 	    s.display();
 		break;
        case 4:
		exit(0);
		default:
		cout<<"invalid input"<<endl;     
	}
	}
	
}