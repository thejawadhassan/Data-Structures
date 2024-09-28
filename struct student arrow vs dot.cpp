#include<iostream>
#include<cstring>
using namespace std;
struct student{
	int roll;
	char name[40];
};
void structread(student *s)
{
   s[0].roll=10;
   strcpy(s[0].name,"jay");
     cout<<s[0].roll<<endl<<s[0].name<<endl;
   	
}
void structreadd(student* obj)
{
   obj->roll=20;
   strcpy(obj->name,"ksi");
   cout<<obj->roll<<endl<<obj->name;
   	
}
main()
{
	student s[5],s2;
	structread(s);
	structreadd(&s2);
}
