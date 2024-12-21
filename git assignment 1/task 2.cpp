#include<iostream>
#include<string>
using namespace std;
#define max 10
struct stack{
		int top;
		int arr[max];
		void initstack()
		{
			top=-1;
		}
		void push(int n)
		{
			if(!isfull())
			{
				top++;
				arr[top]=n;
			}
			else
			cout<<"stack full"<<endl;
			
		}
		int pop()
		{
			int a;
			if(!isempty())
			{
			a=arr[top];
			top--;
			return a;	
			}
			else
			{
				cout<<"stack empty";
				return -1;
			}
		}
	
	bool isfull()
	{
		if(top<max-1)
		{
			return false;
		}
		else 
		return true;
		
	}
	bool isempty()
	{
		if(top>=0)
		{
			return false;
		}
		else 
		return true;
	}
	int precedence(char o) {
		if (o=='+' || o=='-')
		return 1;
		if (o=='*' || o=='/') 
		return 2;
		if (o=='^') 
		return 3;
		
		return 0;
	}
	
	string postfix(string exp) 
	{
		string post="";
		for (int i=0; i<exp.length();i++) 
		{
			char ch=exp[i];
			
			if (isalnum(ch))
			{
				post +=ch;
			} 
			else if (ch=='(')
			 {
				push(ch);  
			} 
			else if (ch==')')
			 {
				while (top>=0 && arr[top] !='(') 
				{
					post += pop();
				}
				pop();
			} 
			else 
			{
				while(top>=0 && precedence(arr[top])>=precedence(ch))
				{
				post += pop();
			   }
				push(ch); 
			}
		}
		
		while (top>=0)
		 {
			post+=pop();
		 }
		return post;
	}
};
main()
{
	stack s;
	s.initstack();
	string exp="(a+B)*(C-D)";
	cout<<"expression converted from infix to postfix is: "<<s.postfix(exp)<<endl;
}