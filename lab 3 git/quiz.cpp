#include<iostream>
using namespace std;
int main()
{ 	
	int n;
	cout<<"enter size of an array :";
	cin>>n;
  	int arr[n];
  	cout<<"enter unique "<<n<<" elements of array: ";
  	for(int i=0;i<n;i++)
  	{ 
 		cin>>arr[i];	
	}
	cout<<"elements of array are: "<<endl;
	for(int i=0;i<n;i++)
  	{ 
 		cout<<arr[i]<<endl;	
	}
	cout<<"reversed array is: "<<endl;
	for(int i=0; i<n/2; i++) 
	{
		
		int temp=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=temp;
	}
	
	for(int i=0;i<n;i++)
  	{ 
 		cout<<arr[i]<<endl;	
	}
	
	return 0;
}