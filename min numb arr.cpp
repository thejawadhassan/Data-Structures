#include <iostream>
using namespace std;
void min(int* a)
{
    int min=a[0];
    for(int i=1;i<5;i++)
    {
    if(min>a[i])
    {
        min=a[i];
    }
    }
    cout<<min;
    
    
}
int main() 
{
   int arr[5]={1,22,333,-42,15};
   min(arr);
    return 0;
}
