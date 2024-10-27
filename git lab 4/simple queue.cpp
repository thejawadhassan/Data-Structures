#include<iostream>
using namespace std;
#define max 5
int front =-1;
int rear=-1;
int arr[max];
void enqueue(int n)
{
	if(front==-1)
	{
		front=0;
	}
	if (rear<max-1)
	{
		rear++;
		arr[rear]=n;
	}
	else
	{
		cout<<"queue full"<<endl;
	}
}
void dequeue()
{
if(front==-1||front>rear)
{
	cout<<"queue empty"<<endl;
}
else
{
	cout<<"element dequeued: "<<arr[front]<<endl;
	front ++;
	if(front>rear)
	{
		front=rear=-1;
	}
}
}
void display()
{
	
	if(front==-1||front>rear)
	{
		cout<<"queue empty"<<endl;
	}
	else
	{
		cout<<"display element:"<<endl;
		for(int i=front;i<=rear;i++)
				{
		 		 cout<<arr[i]<<endl;
				}
	}
}
main()
{
	enqueue(5);
	dequeue();
	dequeue();
	enqueue(11);
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(44);
	display();
	
}