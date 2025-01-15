#include<iostream>
using namespace std;
main()
{
	int *ptr=new int[5];
	for(int i =0;i<5;i++)
	{
		ptr[i]=i;
	}
	int *arr=new int[5];
	for(int i=0;i<5;i++)
	{
		arr[i]=ptr[i];
	}
	delete[]ptr;
	ptr=0;
		for(int i=0;i<5;i++)
	{
		cout<<arr[i];
	}
	
}
