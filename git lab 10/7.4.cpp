#include<iostream>
#include<cstring>
using namespace std;
 bool palindrome(char* a,int start,int end)
 {
 	if(start>=end)
 	{
 		return true;
	 }
	  if(a[start]!=a[end])
	    {
    	   return false;
		}
	palindrome(a,start+1,end-1);	 
 }
main()
{
	char arr[100]="level";
	int length=strlen(arr);
 if(palindrome(arr,0,length-1))
 {
 	cout<<"palindrome"<<endl;
 }
 else
 {
 	cout<<"not palindrome"<<endl;
 }	
}