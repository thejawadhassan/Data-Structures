#include<iostream>
using namespace std;
int k=0;
void prime(int n,int i)
{
	if(i>n)
	{
		if(k>2)
	{
	cout<<"not prime number";	
	}
	else if(k==2)
	{
		cout<<"prime number";
		}	
	return;
	}
	if(n%i==0)
	{
	k++;
	}
	prime(n,i+1);
	}
main()
{
	int numb=14;
	prime(numb,1);
}