#include<iostream>
#include<string>
using namespace std;
struct student{
	int roll;
	string name;
};
void structread(student *s)
{
   s[0].roll=10;
   getline(cin,s[0].name);
     cout<<s[0].roll<<endl<<s[0].name<<endl;
   	
}
main()
{
	student s[5],s2;
	structread(s);
}
