#include<iostream>
using namespace std;
void power(int*b1,int*b2,int*e1,int*e2,int*res)
{
	if(*b1!=*b2)
	{
		cout<<"product not possible";
		exit(0);
	}
	else
	{
		*res=*e1+*e2;
	}
}
main()
{
	int b1,b2,e1,e2,res;
	b1=4;
	e1=2;
	b2=5;
	e2=6;
	res=0;
	power(&b1,&b2,&e1,&e2,&res);	
	cout<<res;
}