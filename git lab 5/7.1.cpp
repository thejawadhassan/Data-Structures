#include<iostream>
using namespace std;
#define max 10
class queue{
	private:
		int arr[max];
		int front;
		int rear;
		int count;
	public:
	queue()
    {
   	    front=-1;
		 rear=-1; 
		 count=0;  
	}
	bool isfull()
	{
		return count==max;
	}
	bool isempty()
	{
		return count==0;
	}
	void enqueue(int n)
{
	
	if (!isfull())
	{
		if(front==-1)
	{
		front=0;
	}
		rear=(rear+1)%max;
		arr[rear]=n;
		count++;
		cout<<"enqueued! \n";
	}
	else
	{
		cout<<"queue full"<<endl;
	}
}
void dequeue(int n)
{
if(isempty())
{
	cout<<"queue empty"<<endl;
}
else if (n > count || n==0)
 {cout << "Not enough elements to dequeue." << endl;} 
 
else
{   int sum=0;
	for(int i=0;i<n;i++)
	{sum=sum+arr[front];
	cout<<"element dequeued: "<<arr[front]<<endl;
	front=(front+1)%max;
	count--;
	}
	cout<<"\naverage of dequeued elements are: "<<sum/n<<endl;
}
}
void display()
{
	
	if(isempty())
	{
		cout<<"queue empty"<<endl;
	}
	else
	{
		cout<<"display element:"<<endl;
        int i=front;
		for(int n=0;n<count;n++)
				{
		 		 cout<<arr[i]<<endl;
		         i=(i+1)%max;
				}
	}
}
};
main()
{
	int option,n;
	queue q;
	while(1)
	{
		cout<<" press 1 to enqueue \n press 2 to dequeue & display elements \n press 3 to display remaining \n press 4 to quit \n";
	 cin>>option;
	  switch(option)
	    {
		   case 1:
		   cout<<"enter number to enqueue: ";
   		   cin>>n; 	
		  q.enqueue(n);	
		  break;	      
		  case 2:
		  cout<<"enter amount of elements u want to dequeue:";
		  cin>>n;	  		  	 	   	       
		  q.dequeue(n);
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