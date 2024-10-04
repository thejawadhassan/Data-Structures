#include<iostream>
using namespace std;
main()
{
	int size,var,count=0;
	cout<<"enter size: ";
	cin>>size;
	int *arr= new int[size];
	cout<<"enter values in array: ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter a var to search and find:";
	cin>>var;
	for(int i=0;i<size;i++)
	{
		if(var==arr[i])
		 {
			count++;		   	   		 	    	
		 }
	}
	cout<<"the number is present this many times in array: "<<count;
	
}