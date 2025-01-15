#include<iostream>
using namespace std;
#define max 5
int arr[max];
int top=0;
void push(int data)
{
	if(top==max)
	cout<<"stack overflow";
	arr[top]=data;
	top=top+1;
}
main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
}
