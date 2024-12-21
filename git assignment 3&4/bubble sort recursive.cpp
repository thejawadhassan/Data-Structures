#include<iostream>
using namespace std;
void sort(int* arr,int n)
{
	if(n==1)
	{return;
	}
	int temp;
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
		temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;	
		}
	}
	sort(arr,n-1);
}
main()
{
	int arr[5]={10,4,33,2,1};
	sort(arr,5);
	cout<<"sorted array is:";
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<endl;
	}
}