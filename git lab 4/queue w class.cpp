#include<iostream>
using namespace std;
class queue{
	private:
		int*arr;
		int front;
		int rear;
		int max;
	public:
	queue(int size)
    {
   	  max=size;
   	  arr=new int[max];
   	    front=-1;
		 rear=-1;   
	}
	~queue()
	{
		delete []arr;
	}
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
		cout<<"enqueued! \n";
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
};
main()
{
	int size,option,n;
	cout<<"enter queue size: ";
	cin>>size;
	queue q(size);
	while(1)
	{
		cout<<" press 1 to enqueue \n press 2 to dequeue \n press 3 to display \n press 4 to quit \n";
	 cin>>option;
	  switch(option)
	    {
		   case 1:
		   cout<<"enter number to enqueue: ";
   		   cin>>n; 	
		  q.enqueue(n);	
		  break;	      
		  case 2:		  		  	 	   	       
		  q.dequeue();
		  break;										   		   		   	    	  	   	        	        
    	  case 3: 
  	      q.display();
          break;
          case 4:
      	   exit(0);
		  default:
		  cout<<"wrong value enter try again! \n";
		  break;	        
		}
	}
}