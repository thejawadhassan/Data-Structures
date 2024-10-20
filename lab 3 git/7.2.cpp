#include<iostream>
using namespace std;
#define size 7 
class stack{
	private:
		int top;
		int arr[size];
	public:
	stack()
  {
	top=-1;						  	   	    	
  }
  
  
  void push(int n)
  {
  	
  	if(top<size-1)
  	{
	top++;
  	arr[top]=n;
  	cout<<"element pushed"<<endl;
  	}
  	else
  	cout<<"stack full"<<endl;
  }
  void pop()
  {
  	
  	if(top>=0)
  	{
  		cout<<"popped element"<<arr[top]<<endl;
	    top--;

	  }
   else
  	{
	  	  cout<<"stack empty"<<endl;
  	}
  }
  void display()
  {
  	if(top==-1)
  	{
  		cout<<"stack empty";
	  }
   else
  	{
	  cout<<"displayed values are: "<<endl;
  	for(int i=0;i<=top;i++)
  	{
  		cout<<arr[i]<<endl;
	  }
	  }
  }
  void nextgreater()
  {
  	if(top==-1)
  	{
  	cout<<"stack empty";	
	  }
   else
   {
   	int nxtgreater;
   	cout<<"the next greater element is: "<<endl;
   	for(int i=0;i<=top;i++)
   	{
   		nxtgreater=-1;
   		for(int j=i+1;j<=top;j++)
   			{
			 	if(arr[j]>arr[i])
				{
				  nxtgreater=arr[j];
				  break;		 		 		   	
				 }			   	
		   }
 	   if(nxtgreater==-1)
 	      {
    	   cout<<arr[i]<<" -> "<<nxtgreater<<endl;
		   }
 	   else
 	      {
       	    cout<<arr[i]<<" -> "<<nxtgreater<<endl;
		   }
     
	   }
   }
  }
};
int main()
{
	stack s;
	int option,n;
	
	do{
	
		cout<<"\n Press 1 to PUSH a value in Stack \n Press 2 to POP a value from Stack \n Press 3 to display the Stack \n Press 4 to Show the next greater element in the Stack \n Press 5 to exit program \n";
	    cin>>option;
		    
			switch(option)
      {
      	case 1:
      		cout<<"enter value u want to push: ";
			cin>>n;		 
			  s.push(n);
		   break;
		 case 2:		 
			  s.pop();
		   break;  	
		   case 3:		 
			  s.display();
		   break;
	       case 4:
  	        s.nextgreater();
		   break;
		   		    
		   		   	
	  } 
  }
  while(option!=5);
	return 0;
}