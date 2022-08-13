#include <iostream>
//Traversing array element in linear form
using namespace std;

int main()
{ 
 int a;
 cout<<"Enter size of array ";
 cin>>a;
 int arr[a];
 for (int i = 0; i < a; i++)
 {
    cout<<"Enter array element at index "<<i<<" ";
    cin>>arr[i];
 }
int i=0;
while (i<a)
{
  cout<<arr[i]<<" ";
  i++;
}
 

 return 0;
}