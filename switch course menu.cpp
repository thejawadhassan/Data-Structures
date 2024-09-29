#include<iostream>
#include<string>
using namespace std;
int count=0;
struct course{
	int id;
	string title;
	float crdthrs;
	
};
void add(course *c)
{
	if(count<=4)
	{
	cout<<"enter course id, title and credit hours:";
	cin>>c[count].id>>c[count].title>>c[count].crdthrs;
	count++;
    }
}
void update(course *c)
{
		cout<<"update course id, title and credit hours:";
	cin>>c[count-1].id>>c[count-1].title>>c[count-1].crdthrs;
}
void remove(course *c)
{
	c[count+1].id=0;
	c[count+1].title="none";
	c[count+1].crdthrs= 0;
	cout<<"course removed";
	
}
void search(course *c)
{
	string name;
	cout<<"enter course title you want to search:";
	cin>>name;
	
	for(int i =0;i<5;i++)
	{
		if( name==c[i].title)
		{
			cout<<"course found";
		}
	}
}
void display(course *c)
{
	for(int i =0;i<5;i++)
	{
		cout<<"courses are:"<<c[i].id<<c[i].title<<c[i].crdthrs<<endl;
		
	}
}
main()
{
	course c[5];
	char x;
	cout<<"Main Menu \n --------------- \nPress 1 to add a Course \nPress 2 to update a Course \nPress 3 to delete a Course \nPress 4 to search and display a Course \nPress 5 to display all Courses \nPress e to exit the program \n";
	cin>>x;
	while(x!='e')
	{
	switch(x)
	{
		case '1':
			add(c);
			break;
		case '2':
		    update(c);
			break;
		case '3':
			remove(c);
			break;
		case '4':
			search(c);
			break;
		case '5':
			display(c);
			break;
			
	}
    }
	exit(0);
	
	
}
