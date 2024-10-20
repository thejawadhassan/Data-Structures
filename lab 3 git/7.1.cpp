#include<iostream>
using namespace std;
int size;
class stack{
	private:
		int top;
		char *arr;
	public:
	stack(int max)
  {
	top=-1;
	arr=new char [max];							  	   	    	
  }
  ~stack()
  {
  	delete[] arr;
  }
  void push(char n)
  {
  	
  	if(top<size-1)
  	{
	top++;
  	arr[top]=n;
  	cout<<"element pushed"<<endl;
  	}
  	else
  	cout<<"stack full"<<endl;
  }
  void pop()
  {
  	
  	if(top>=0)
  	{
  		cout<<"popped element: "<<arr[top]<<endl;
	    top--;
	  }
   else
  	{
	  	cout<<"stack empty"<<endl;
  	}
  }
  void display()
  {
  	if(top==-1)
  	{
  		cout<<"stack empty"<<endl;
	 }
  	 else
  	{
	  cout<<"all stack values are: \n";
  	for(int i=0;i<=top;i++)
  	{
  		cout<<arr[i]<<endl;
	  }
   }
   }
};
int main()
{
	
	cout<<"enter max size of stack: ";
	cin>>size;
	stack s(size);
	s.push('a');
	s.push('b');
	s.push('c');
	s.display();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	return 0;
}