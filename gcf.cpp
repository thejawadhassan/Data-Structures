#include<iostream>
using namespace std;
int gcf(int a,int b)
{
	int r;
 if (a>b)
 {
 while (b!=0)
 {
 	r=a%b;
 	a=b;
 	b=r;
 }
 return a;
 }
 else if(b>a)
 {
 	while (a!=0)
 	{
 	  r=b%a;
	  b=a;
	  a=r; 	
	}
	 return b;
 	
 }
}
main()
{
int alpha,beta;
alpha=12;
beta=16;
cout<<"gcf is: "<<gcf(alpha,beta);
}
