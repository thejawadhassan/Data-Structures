#include<iostream>
using namespace std;
float area(float,float,float);
main()
{
float h,a,b;
a=30.2;
b=33.2;
h=2.5;
cout<<area(a,b,h);
}
float area(float a,float b,float h)
{
	float area=0.5*(a+b)*h;
	return area;
}
