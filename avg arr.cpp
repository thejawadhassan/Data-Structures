#include<iostream>
using namespace std;
float arr_avg(int *a,int size)
{
	float avg=0;
	for(int i=0;i<size;i++)
	{
	avg +=a[i];
    }
    return avg/size;
}
void display(int a[],int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<a[i]<<endl;
	}
}
main()
{
	int arr[6]={1,2,3,4,5,6};
	cout<<arr_avg(arr,6);
	display(arr,6);
}
