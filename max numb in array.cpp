#include <iostream>
using namespace std;
void max(int* a)
{
    int max=a[0];
    for(int i=1;i<5;i++)
    {
    if(max<a[i])
    {
        max=a[i];
    }
    }
    cout<<max;
    
    
}
int main() 
{
   int arr[5]={1,22,333,42,15};
   max(arr);
    return 0;
}
