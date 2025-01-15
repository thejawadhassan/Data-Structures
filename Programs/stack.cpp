//linear dynamic data structure:
#include <iostream>
#include<stack>
using namespace std;
main()
{
	//filo and lifo(first in last out or last in fisrt out)
	
	stack<int>num;
		num.push(1);
		/*num.push(2);
		num.push(3);
		num.push(3);
		num.push(1000000000);
		num.push(4);*/
		num.pop();
	if (num.empty())
	{cout<<"empty";
	}
	else
	{
		cout<<num.top()<<endl;
		cout<<num.size()<<endl;
		
	}
	cout<<num.empty();
}
