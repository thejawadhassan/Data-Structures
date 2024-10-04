#include<iostream>
using namespace std;
void max(int a[])
{
	int max=a[0];
	int *ptr=a;
	for(int i =1; i<5;i++)
	{
		if(max<a[i])
	{
		max=a[i];
		ptr=&a[i];			 	  			
	}
	}
	cout<<"max value is: "<<max<<" with address : "<<ptr;
}
int main()
{
	int arr[5];
	cout<<"enter 5 values:"<<endl;
	for(int i=0;i<5;i++)
	{
	cin>>arr[i];	
	}
	max(arr);
	return 0;
}