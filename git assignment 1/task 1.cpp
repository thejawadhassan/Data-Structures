#include<iostream>
using namespace std;
#define max 10
struct queue{
    int front;
    int rear;
    int count;
    int arr[max];     
    int priority[max]; 
    
    void initqueue() 
	{
        front=rear= -1;
        count=0;
    }

    bool isempty() 
	{
        return count==0;
    }

    bool isfull() 
	{
        return count==max;
    }

    void enqueue(int n, int p) 
	{
        if (!isfull())
		 {
            if (front == -1) 
			{
                front=0;
                rear=0;
            } 
			else 
			{
                int i=rear;
                while (i>=front && priority[i]<p)
				 {
                    arr[(i+1)%max]=arr[i];        
                    priority[(i+1)%max]=priority[i];
                    i--;
                }
                rear=(rear+1)%max;
            }
            arr[rear]=n;         
            priority[rear]=p;     
            count++;
        }
		 else 
		{
            cout<<"Queue full"<<endl;
        }
    }

    int dequeue() 
	{
        if (!isempty()) 
		{
            int a=arr[front];
            front=(front+1)%max;
            count--;
            return a;
        } 
		else
		 {
            cout<<"Queue empty"<<endl;
            return -1;
        }
    }

    void display() 
	{
        cout<<"Display:"<<endl;
        if(!isempty()) 
		{
            int i=front;
            for (int n=0; n<count; n++)
			 {
                cout<<arr[i]<<"(Priority: "<<priority[i]<<")"<<endl;
                i=(i+1)%max;
            }
        } 
		else 
		{
            cout<<"Empty queue"<<endl;
        }
    }
};

main() 
{
    int opt,n,p;
    queue q; 
    q.initqueue();
    cout<<"Select option:"<<endl;

    while (1)
	{
        cout<<"\n1 for enqueue, 2 for dequeue, 3 for display & 4 for exit \n ";
        cin>>opt;
        switch (opt)
		 {
            case 1:
                cout<<"Enter element: ";
                cin>>n;
                cout<<"Enter priority: ";
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
                cout<<"Invalid selection"<<endl;
        }
    }
}