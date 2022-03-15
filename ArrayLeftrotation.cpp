#include <iostream>
using namespace std;
void leftrotation(int array[] , int size, int rotation)
{
    for (int y = 0; y < rotation; y++)
    {
      int q = array[0];
      for (int k=0; k<(size-1); k++) {
      array[k] = array[k+1];
      }
      array[(size-1)]=q;
    }
    
}
int main()
{
    int n;
    int d;
    cin>>n>>d;
    int arr[n];
    for (int i =0; i<n; i++) {
    cin>>arr[i];
    }

    leftrotation(arr,n,d);
    
     for (int u  = 0; u<n; u++)
     {
       cout<<arr[u]<<" ";
     }
    return 0;
}
