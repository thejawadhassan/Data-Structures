#include <iostream>
using namespace std;
int a = 5;
int  b = 6;
void swap()
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	
	swap();
	cout << a << "\n"
		 << b;
}
