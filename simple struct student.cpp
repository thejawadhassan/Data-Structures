#include<iostream>
#include<cstring>
using namespace std;
struct student{
	int roll;
	char name[40];
};
main()
{
	student s[5];
	s[0].roll=10;
	strcpy(s[0].name,"ali");
	cout<<s[0].name<<endl<<s[0].roll;
	
}
