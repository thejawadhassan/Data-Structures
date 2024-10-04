#include<iostream>
#include<cstring>
using namespace std;
void ChangeCase(char *a)
{
	while(*a!='\0')
	{
		if(isupper(*a))
		 {
			*a= tolower(*a);		   				   	
		 }
		   else
     {
		*a = toupper(*a);		     								     	
	 } 
	  *a++;
	}
}
main()
{
	int size;
	cout<<"enter size:";
	cin>>size;
	char *arr=new char [size];
	cout<<"enter alphabets : ";
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}
	ChangeCase(arr);
	cout<<"changed case letters are: "<<endl;
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	delete [] arr;
}