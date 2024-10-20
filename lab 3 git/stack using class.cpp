#include<iostream>
using namespace std;
int size;
class stack{
	private:
		int top;
		int *arr;
	public:
	stack(int max)
  {
	top=-1;
	arr=new int [max];							  	   	    	
  }
  ~stack()
  {
  	delete[] arr;
  }
  void push(int n)
  {
  	
  	if(top<size-1)
  	{
	top++;
  	arr[top]=n;
  	cout<<"element pushed "<<endl;
  	}
  	else
  	cout<<"stack full"<<endl;
  }
  void pop()
  {
  	
  	if(top>=0)
  	{
  		cout<<"element popped: "<<arr[top]<<endl;
	    top--;
	  }
   else
  	{
	  cout<<"stack empty"<<endl;
  	}
  }
};
int main()
{
	
	cout<<"enter max size of stack: ";
	cin>>size;
	stack s(size);
	s.push(10);
	s.push(20);
	s.push(30);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	return 0;
}