#include<iostream>
using namespace std;
int model;
string name;
void info()
{
	cout<<"whats the model and name:";
	cin>> model;
	cin>>name;
}
void display()
{
	info();
	cout<<"the ans is: ";
	cout<<model;
	cout<<name;
}
main()
{
	display();
}
