#include<iostream>
using namespace std;
void FindLarge(int *p,int size)
{
	int n,min,c=0,d=0;
	cout<<"enter non negative integers";
	for(int i=0;i<size;i++)
	{
		cin>>p[i];
	}
	cout<<"enter the non negative input number:";
	cin>>n;
	for(int i=0;i<size;i++)
	{
		
		if(p[i]<n)
  		{
		 p[i]=0;		   		   		     	
		 }
	}
	for(int i=0;i<size;i++)
	{
		
		if(p[i]>0)
  		{
   		 c++;		   		   		     	
		 }
	}
	int *temp=new int [c];
	for(int i=0;i<size;i++)
	{
		
		if(p[i]>0)
  		{
   		 temp[d]=p[i];
			d++;		   		   		     	
		 }
	}
	min =temp[0];
	for(int j=1;j<c;j++)
	{
		if(min>temp[j])
		  {
		     	min=temp[j];
					   							 	   	
		   }
	}
	
	cout<<"largest number next to input number is: "<<min;
	delete [] temp;
}
void main()
{
	
	int size;
	cout<<"enter size of array from 0 to 15:";
	cin>>size;
	int *arr= new int[size];
	FindLarge(arr,size);
    delete [] arr;	
}
