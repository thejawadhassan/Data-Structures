#include<iostream>
using namespace std;
void pass(int *l,int*m)
{
	*l=*l+1;
	*m=*m+1;
}
int main()
{
	int *a= new int;
	int *b= new int;
	*a=1;
	*b=2;
	pass(a,b);
	cout<<"*a="<<*a<<endl<<"*b="<<*b;
	delete a;
	delete b;
	return 0;
}