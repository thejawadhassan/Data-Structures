#include<iostream>
using namespace std;
struct queue{
	private:
	int front;
	int rear;
	int arr[20];
	int pq[20];
	int max;
	public:
	void innit()
	{
		max =20;
		front=rear=-1;
	}	

	bool isempty()
{
	if(front==-1||front>rear)
	{return true;
	}
	else
	return false;
}
bool isfull()
{
	if(rear<max-1)
	{
		return false;
	}
	else 
	return true;
}
void enqueue(int n,int p)
{
	if(!isfull())
	{
		if(front==-1)
		{
			front=0;
		}
		rear++;
		pq[rear]=p;
		arr[rear]=n; 
		priority();
	}
	else
	cout<<"queue full";
}
int dequeue()
{
	int a;
	if(!isempty())
	{
		a=arr[front];
		front++;
		if(front>rear)
		{
			front=rear=-1;
		}
		return a;
	}
	else
	{
	cout<<"queue empty";
	return -1;}
}
void display()
{
	cout<<"display:"<<endl;
	if(!isempty())
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<arr[i]<<endl;
		}
	}
	else
	cout<<"empty queue"<<endl;
}
void priority()
{
	int temp;
	for(int i=front;i<=rear;i++)
	{
		for(int j=front;j<rear;j++)
		{
			if(pq[j]<pq[j+1])
			{
				temp=pq[j];
				pq[j]=pq[j+1];
				pq[j+1]=temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	
		
	}
}
};
main()
{
	int opt,n,p;
	queue q;
	q.innit();
	cout<<"select option:"<<endl;
	while(1)
	{
		cout<<"\n1 for enqueue with priority, 2 for dequeue, 3 for display & 4 for exit \n ";
		cin>>opt;
		switch(opt)
		{
			case 1:
			cout<<"enter element:";
			cin>>n;
			cout<<"enter priority:";
			cin>>p;
			q.enqueue(n,p);
			break;
			case 2:
			cout<<q.dequeue()<<endl;
			break;
			case 3:
			q.display();
			break;
			case 4:
			exit(0);
			default:
			cout<<"invalid selection"<<endl;
		}
	}
}