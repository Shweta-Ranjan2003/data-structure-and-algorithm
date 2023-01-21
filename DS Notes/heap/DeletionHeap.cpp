#include <iostream>
using namespace std;
void deletion(int arr[] , int size ){
  arr[0] = arr[size];
  size--;
  int max;
  int leaf = (size/2)+1;
  for (int i = 0; i < (leaf-1); i++)
  {
     if (arr[2*i]>arr[(2*i)+1]&& arr[2*i]>arr[i])
     {
        int temp = arr[i];
        arr[i]= arr[2*i];
        arr[2*i] = temp;
     }
      else if (arr[(2*i)+1]>arr[2*i]&& arr[(2*i)+1]>arr[i])
     {
        int temp = arr[i];
        arr[i]= arr[(2*i)+1];
        arr[(2*i)+1] = temp;
     }
     else continue;
  }
  for (int i = 0; i < size; i++)
  {
    cout<<arr[i]<<" ";
  }
  
}
int main()
{ 
 int size;
 cout<<"Enter the size of heap: ";
 cin>>size;
 int arr[size];
 cout<<"Enter elements of heap: ";
 for (int i = 0; i < size; i++)
 {
    cin>>arr[i];
 }
 deletion(arr , size);
 return 0;
}