#include<iostream>
using namespace std;
class list{
	private:
		int*arr;
	    int size;
		int count;
   public:
   	list(int n)
   	{ size=n;
  	arr=new int[size];
  	count =0;
	   }
    ~list()
    {
    	delete [] arr;
	}
    bool isfull()
    {
    return count==size;	
	}
	bool isempty()
	{
	return count==0;	
	}
    void insert(int val)
    {
    	if(!isfull())
    	{
    	  arr[count]=val;
		  count++; 
		  cout<<"element added"<<endl;	
		}
		 else
	  cout<<"list full";
	}
	int totalElements()
	{
		cout<<"total elements are:";
		return count;
	}
	void display()
	{
		if(!isempty())
	{
			cout<<"list elements are: "<<endl;
		for(int i=0;i<count;i++)
				{
 	              cout<<arr[i]<<endl;
				}
	}
	else
	cout<<"list is empty!"<<endl;
    }
    void update(int old,int change)
    {
    	for(int i=0;i<count;i++)
				{
 	              if(arr[i]==old)
      			  {
   				   	arr[i]==change;
  	     	        cout<<"element updated"<<endl;
			      }  
				}	
	}
	void search(int a)
	{int n=0;
	for(int i=0;i<count;i++)
				{
 	              if(arr[i]==a)
      			  {
      			   	n++;		     	
   				   cout<<"element found"<<endl;
			      }  
				}
				if(n==0)
				{
	               cout<<"element not found"<<endl;
					}	
	}
	void remove()
	{
		if(!isempty())
		{
		count--;
		cout<<"last element removed, all left elements are:"<<endl;
		for(int i=0;i<count;i++)
				{
   				   	cout<<arr[i]<<endl;  				
            	}
       }
       else 
       cout<<"list empty"<<endl;
    }
};

main()
{
	list l(10);
	l.insert(10);
	l.search(10);
	l.update(10,20);
	l.display();
	cout<<l.totalElements()<<endl;
	l.remove();
	cout<<"\nis empty:"<<l.isempty()<<endl;
	cout<<"is full: "<<l.isfull();
	
}