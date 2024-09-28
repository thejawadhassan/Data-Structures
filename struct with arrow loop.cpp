#include<iostream>
#include<cstring>
using namespace std;
struct student{
	int roll;
	char name[40];
};
void structread(student *s)
{
  
   
   cin>>s->roll;
   strcpy(s->name,"ali");
  
}
main()
{
	student s[5];
	for(int i=0;i<5;i++)
   {
   	structread(&s[i]);
   }
	for(int i=0;i<5;i++)
   {
   cout<<s[i].name<<endl<<s[i].roll<<endl;
   }

}
