#include<iostream>
using namespace std;
void recursive(int *arr,int size)
{
	if(size==10)
	{
		return;
	}
	cout<<arr[size]<<endl;
	recursive(arr,size+1);
}
main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	recursive(arr,0);
}