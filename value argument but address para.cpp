#include<iostream>
using namespace std;
void change(int &arr)
{
	arr=20;
}
main()
{
	int a=10;
	cout<<a<<endl;
	change(a);
	cout<<a;
}
