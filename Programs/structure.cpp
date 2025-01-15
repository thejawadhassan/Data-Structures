#include<iostream>
using namespace std;
struct phone{
	int model;
	string name; 
}p1;
void info()
{
	cin>>p1.name;
	cin>>p1.model;
}
void display()
{
	info();
	cout<<"it is";
	cout<<p1.name;
	cout<<p1.model;
}
main()
{
	display();
}
