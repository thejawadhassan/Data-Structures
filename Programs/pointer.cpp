#include<iostream>
using namespace std;
main()
{
	int a =10;
	void* ptr=&a;
	cout<<*(static_cast<int*>(ptr));
	//or
	cout<<endl<<*((int*)ptr);
	
	
}
