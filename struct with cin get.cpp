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
   cin.get(s[0].name,40);
     cout<<s[0].roll<<endl<<s[0].name<<endl;
   	
}
main()
{
	student s[5],s2;
	structread(s);

}
