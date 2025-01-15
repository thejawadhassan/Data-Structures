#include<iostream>
using namespace std;
class robot{
	public:
	string name;
	string color;
	int weight;
	robot(string names,string colr,int wght)
	{
		name=names;
		color=colr;
		weight=wght;
	}
	void display()
	{
		cout<<name;
		cout<<color;
		cout<<weight;
	}
};
main()
{
	 
	 robot r1("alpha","red",80),r2("beta","blue",100);
	r1.display();
	r2.display();
}
