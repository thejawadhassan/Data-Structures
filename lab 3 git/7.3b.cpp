#include<iostream>
#include<cstring>
using namespace std;
#define size 20
class stack{
	private:
		int top;
		char arr[size];
	 public:
	  	stack()
		  {
			 top=-1; 	  	      	
		 }
        void push(char n)
        {
        if(top<size-1)
		{
		 	top++;
			 arr[top]=n;
			}
			else
			cout<<"stack full";	
		}
		 char pop()
   		 {char res;
  		  if(top>=0)
 			  {
 		  	    res=arr[top];
		   	    top--;
    	     	return res;
			   }
	     else
		      {
			    cout<<"stack empty";     
				return '\0';
			  }
		  }
      void sequence()
      {
      	char ch;
      	cout<<"enter characters (if f or F then end):"<<endl;
      	while(1)
		  {cin>>ch;
		  if(ch=='f'|| ch=='F')
		  	{
		 	break;
			}  
			if(top!=-1 && arr[top]==ch)
			{
			pop();
		 	}  
			 else
			 {
			  push (ch);	  	
			} 	  
				  			 	   	  
	      }
	}
	void print()
	{
	if (top==-1)
	{
		cout<<"stack empty";
		}
		else
		for(int i=0;i<=top;i++)
		{
		 	cout<<arr[i];
			}	
	}
        	
};
main()
{
stack s;
s.sequence();
cout<<"new sequence is: \n";
s.print();
}