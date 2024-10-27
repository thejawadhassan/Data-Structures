#include<iostream>
using namespace std;
class vehicle{
	private:
		string*arr;
		int front;
		int rear;
		int max;
	public:
	vehicle(int size)
    {
   	  max=size;
   	  arr=new string[max];
   	    front=-1;
		 rear=-1;   
	}
	~vehicle()
	{
		delete []arr;
	}
	void enqueue(string n)
{
	if(front==-1)
	{
		front=0;
	}
	if (rear<max-1)
	{
		rear++;
		arr[rear]=n;
		cout<<"vehicle entered! \n";
	}
	else
	{
		cout<<"parking full"<<endl;
	}
}
void dequeue()
{
if(front==-1||front>rear)
{
	cout<<"parking empty no vehicle yet"<<endl;
}
else
{
	cout<<"vehicle departed: "<<arr[front]<<endl;
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
		cout<<"parking lot empty, no vehicle"<<endl;
	}
	else
	{
		cout<<"displaying all vehicle model number in parking lot:"<<endl;
		for(int i=front;i<=rear;i++)
				{
		 		 cout<<arr[i]<<endl;
				}
	}
}
};
main()
{
	int size,option;
	string n;
	cout<<"enter how many vehicles can fit in parking lot: ";
	cin>>size;
	vehicle v(size);
	while(1)
	{
		cout<<" press 1 for vehicle arrival in parking \n press 2 for vehicle departure from parking \n press 3 to show all vehicles \n press 4 to quit \n";
	 cin>>option;
	  switch(option)
	    {
		   case 1:
		   cout<<"enter vehicle model number for arrival in parking: ";
   		   cin>>n; 	
		  v.enqueue(n);	
		  break;	      
		  case 2:		  		  	 	   	       
		  v.dequeue();
		  break;										   		   		   	    	  	   	        	        
    	  case 3: 
  	      v.display();
          break;
          case 4:
      	   exit(0);
		  default:
		  cout<<"wrong value enter try again! \n";
		  break;	        
		}
	}
}