#include<iostream>
using namespace std;
int stack [5];
int top=-1;
bool isstackfull()
{
    if(top==5)
    {
        cout<<"stack is full";
        return true;
    }
    else
    return false;
}
bool isstackempty()
{
     if(top==-1||stack[top]==0)
    {
        cout<<"stack is already empty";
        return true;
        
    }
    else
    return false;
}
void push(int n)
{
      top++;
    if(!isstackfull())
    {
      
        stack[top]=n;
    }
}
int pop()
{
    if(!isstackempty())
    {
        int r=stack[top];
        stack[top]=0;
        top--;
        return r;
    }
}
int main()
{
	int x;
	push(4);
	push(5);
	push(5);
	push(5);
	push(5);
    cout<<pop();
	return 0;
}
