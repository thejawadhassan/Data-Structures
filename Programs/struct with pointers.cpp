#include<iostream>
using namespace std;
struct person{
	string name;
	int id;
	
};
void display(person*p1,person*p2)
{
	cout<<p1->name;
	cout<<p1->id<<endl;
	cout<<(*p2).name;
	cout<<(*p2).id;
}
main()
{
	person p1,p2;
	p1.name="ali";
	p1.id=3310;
	p2.id=2210;
	p2.name="jawad";
    display(&p1,&p2);
}
