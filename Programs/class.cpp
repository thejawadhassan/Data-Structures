#include<iostream>
using namespace std;
class student{
	public:
	int id;
	string name;
	student()
	{
		id=0;
		name="jawadhas";
	}
    student(int stdid,string stdname)
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
	student s;
	s.display();
	student s1(22,"zafar");
	s1.display();
	student *s2=new student(33,"ali");
	s2->display();
}

