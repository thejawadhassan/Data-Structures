#include<iostream>
using namespace std;
int main()
{
	int size;
	cout<<"enter size of array:";
	cin>>size;
	int *array= new int [size];
	for(int i=0;i<size;i++)
	{
		array[i]=i+1;
	 	cout<<array[i]<<" ";
	}
	delete [] array;
	
	return 0;
}