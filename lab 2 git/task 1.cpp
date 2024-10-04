#include<iostream>
using namespace std;
int main()
{
	int numbers[5]={16,2,77,40,12071};
	for(int i=0;i<5;i++)
	{
		cout<<numbers[i]<<endl;
	}
	int *arrayptr = new int [10];
	for(int i=0;i<10;i++)
	{
		arrayptr[i]=i;
  		cout<<arrayptr[i]<<endl;
	}
	return 0;
}