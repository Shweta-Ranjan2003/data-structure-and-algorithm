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
    return count;
}
int Deletion(int arr[],int size , int key){
    int pos = findPos(arr , size , key);
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
    int pos , key;
     cout<<"enter key you want to delete: ";
     cin>>key;
     
    cout<< "\nBefore Deletion: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
 
    // Inserting key
    size = Deletion(arr, size, key);
 
    cout << "\nAfter Deletion: ";
    for (int i = 0; i < size; i++)
        cout << arr[i]<< " ";
 
    return 0;
}