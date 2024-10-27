#include<iostream>
using namespace std;
class customer{
	private:
		string name;
         int id;
         float bill;
  public:
  	customer(string n,int i,float b)
  	{
  		name=n;
	    id=i;
  		bill=b;	   			     
	  }
	void output()
	{
		cout<<name<<endl;
	}
};
class queue{
	private:
		customer**arr;
		int front;
		int rear;
		int max;
		int c;
		int t=0;
	public:
	queue(int size)
    {
   	  max=size;
   	  arr=new customer*[max];
   	    front=-1;
		 rear=-1;   
	}
	~queue()
	{
		delete []arr;
	}
	void enqueue(string n,int i,float b)
{
	if (rear<max-1)
	{	
	if(front==-1)
	{
		front=0;
	}
	customer* c=new customer(n,i,b);
		rear++;
		arr[rear]=c;
		t=t+5;
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
	cout<<"no customers"<<endl;
}
else
{
	cout<<"customer checked out: ";
	arr[front]->output();
	front ++;
	c++;
	t=t-5;
	if(front>rear)
	{
		front=rear=-1;
	}
}
}
int display()
{
return c;	
}
int remain()
{
	return t;
}
};
main()
{
	int size,option,i;
	string n;
	float b;
	cout<<"enter total customer: ";
	cin>>size;
	queue q(size);
	while(1)
	{
		cout<<"\nPress 1 to add new customer to queue \nPress 2 to remove a customer from queue \nPress 3 to Calculate the total number of customers served \nPress 4 to Calculate the time required to serve all the remaining customers \nPress 5 to quit \nEnter choice: ";
	 cin>>option;
	  switch(option)
	    {
		   case 1:
		   cout<<"enter customer name: "<<endl;
   		   cin>>n; 	
		   cout<<"enter customer id: "<<endl;
   		   cin>>i;
  		    cout<<"enter customer bill: "<<endl;
   		   cin>>b; 
		  q.enqueue(n,i,b);	
		  break;	      
		  case 2:		  		  	 	   	       
		  q.dequeue();
		  break;										   		   		   	    	  	   	        	        
    	  case 3: 
    	    cout<<"total number of customer served:"<<q.display();
          break;
          case 4:
          	cout<<"time required to serve remaining customers: "<<q.remain();
      	   break;
   	      case 5:
   	      exit(0);
		  default:
		  cout<<"wrong value entered, try again! \n";	        
		}
	}
}