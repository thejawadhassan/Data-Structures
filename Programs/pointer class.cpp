#include<iostream>
using namespace std;
class student{
	public:
		int id;
		string name;
		student()
		{
			id=100;
			name="jawad";
		}
	student(int stdid, string stdname)
	{
		id=stdid;
		name=stdname;
	}
	void display()
	{
		cout<<id;
		cout<<name;
	}
};
main()
{
student *s=new student();
s->display();
}
