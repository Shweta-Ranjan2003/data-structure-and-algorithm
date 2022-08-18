#include <iostream>
using namespace std;
int findPos(int arr[],int size , int key){
    int count = 0;
    while (count<size)
    {
        if (arr[count]==key)
        {
            return count;
        }
        else
        count++;
        
    }
    return -1;
}
int Deletionsearch(int arr[],int size , int key){
    int pos = findPos(arr , size , key);
    if (pos==-1)
    {
        return -1;
    }
    else{
    while (pos<size)
    {
      arr[pos] = arr[pos+1];
      pos++;
    }
    return (size-1);
    }
    
}
int Deletion(int arr[],int size , int pos){
    while (pos<size)
    {
      arr[pos] = arr[pos+1];
      pos++;
    }
    return (size-1);
    
}
int main()
{ int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int pos , key;
     cout<<"enter key you want to delete: ";
     cin>>key;
     
    int sizee = Deletionsearch(arr, size, key);
    if (sizee==-1)
    {
        cout<<"Element not found in array"<<endl;
    }
    else{
    
    cout << "\nAfter Deletion: ";
    for (int i = 0; i < sizee; i++){
        cout << arr[i]<< " ";
    }
    }
    cout<<endl;
    cout<<"Enter the index you want to remove element: ";
    cin>>pos;
    int sz;
     sz = Deletion(arr , size , pos);
    for (int i = 0; i < sz; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}