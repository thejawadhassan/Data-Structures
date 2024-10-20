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
			  }
		  }
        int reversal(int l,string exp)
        {
        for(int i=0;i<l;i++)
		{
		 	if(exp[i]=='{')
 	  		{
 			  push('1');		   		
  		  }
  		     	if(exp[i]=='}')
 	  		{
 			  pop();		   		
  		  }
						    	  
		}
		return (top+1)/2;	
		}
	
};
main()
{
stack s;
string exp="{{}}{{{{}}{{{{}}{{";
int l=exp.length();
if(l%2)
{
	cout<<"expression is odd, balanced is not possible";
	exit(0);
}
	cout<<"the min number of bracket reversal needed: "<<s.reversal(l,exp);
}