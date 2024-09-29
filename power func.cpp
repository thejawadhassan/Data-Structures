#include<iostream>
using namespace std;
int power(int numb,int exp)
{
	int res=1;
	for(int i=0;i<exp;i++)
	{
		res*=numb;
	}
	return res;
}
main()
{
	int numb,exp;
	numb=2;
	exp=5;
	cout<<power(numb,exp);
}
