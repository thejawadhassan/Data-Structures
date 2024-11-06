#include<iostream>
#include<string>
using namespace std;
class vehicle{
	private:
	int front;
	int rear;
	string *arr;
	int max;
	int count;
	public:
		vehicle(int size)
		 {
				max=size;
 		     arr= new string[max];
			  rear=-1;
			front=-1;
			count=0;				 		 	 		     	 
 	         
				 		 	
		 }
                 ~vehicle()
                     {
                             delete []arr;
                       }
		   bool isempty()
		   	 {
				return count==0;  	   	 	   	
			 }
		 bool isfull()
		 	   {
			   	 return count==max;	     	
				}
		   void enqueue(string n)
		   	  {
				 if(!isfull())
				 {
				  	if(front==-1)
					  {
					   	front=0;		 				  	
		              }	
					  rear=(rear+1)%max;
					  arr[rear]=n;
					  count++;
					  cout<<"vehicle arrived in parking"<<endl;   	  	
				  }
				  else
				  cout<<"parking full."<<endl;;  	   	 	   	
			  }
	  string dequeue()
	    {
		    if(!isempty())
				 {
					  string a=arr[front];
					  front=(front+1)%max;
					  count--;
					  return a;	  	
				  }
				  else
				 { string l="null";
				   cout<<"parking lot empty."<<endl;
			      return  l;
		        	}
		}
		  void display()
	    {
		    if(!isempty())
				 {
  	 	              cout<<"display vehicles models:";
  					   int  i=front;  
  					   	for(int n=0;n<count;n++)
							 {
							  	cout<<arr[i]<<endl;
								  i=(i+1)%max;					   					 	
								}    	
				  }
				  else
				 { 
				   cout<<"parking lot empty."<<endl;
			      
		        	}
		}
		
	
};
void main()
{
	int size,option;
	string model;
	cout<<"enter how many vehicle will be in the parking: ";
	cin>>size;
	vehicle v(size);
	while(1)
	{
		cout<<" press 1 for vehicle arrival in parking \n press 2 for vehicle departure from parking\n press 3 to display cars in parking \n press 4 to quit:  ";
		cin>>option;
		switch(option)
        {
        	case 1:
       		cout<<"enter vehicle model model number: ";
            cin>>model;
        	v.enqueue(model);
        	break;
        	case 2:
       		cout<<"departed vehicle model number: ";
        	cout<<v.dequeue()<<endl;
        	break;
        	case 3:
       		v.display();
		     break;
        	case 4:
       		exit(0);
    		default:
			cout<<"wrong option entered, try again!"<<endl;		
		}
	}
}