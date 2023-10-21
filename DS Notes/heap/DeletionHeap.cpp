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

void deleteFromHeap(int arr[],int size){
   if(size==0){
      return;
   }
   arr[1]=arr[size];
   size--;
   int i=1;
   while(i<size){
      int left=2*i;
      int right=2*i+1;
      if(left<size && arr[i]<arr[left]){
         swap(arr[i],arr[left]);
         i=left;
      }
      else if(right<size && arr[i]<arr[right]){
         swap(arr[i],arr[right]);
         i=right;
      }
      else return;
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