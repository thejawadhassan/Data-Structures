#include<iostream>
using namespace std;
void odd(int i,int j)
{
	if(i>j)
	{	
	return;
	}
	if(i%2!=0)
	{
	cout<<i<<" is odd  number"<<endl;
	}
	odd(i+1,j);
}
main()
{
	int a,b;
	cout<<"enter two number range: ";
	cin>>a>>b;
	odd(a,b);
}