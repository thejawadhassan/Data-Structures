#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
main()
{
	int a = 5, b = 6;
	swap(&a, &b);
	cout << a << "\n"
		 << b;
}
