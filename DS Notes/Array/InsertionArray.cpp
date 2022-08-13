#include <iostream>
using namespace std;
/*
Algo:- 1. [Initialize counter] Set J = size.
2. Repeat steps 3 and 4 while J>=pos
3. [Move Jth element downward ] Set A[J+1] = A[j]
4. [decrease counter] set j=j-1
{end of step 2 loop}
5. [Insert element] set A[pos]=key
6. [reset size] size = size+1
7. exit
*/
int Insertionatnth(int arr[] , int size , int key , int pos){
    int J = size-1;
    while (J>=pos)
    {
        arr[J+1]=arr[J];
        J--;
    }
    arr[pos]=key;
    return (size+1);
    

}
// int Insertionsorted(int arr[],int size,int key,int capacity){
//     if (size>=capacity)
//     {
//         return 0;
//     }
//     else{
//     int i;
//     for (i = size-1; (i <= 0 && arr[i]>key); i--)
//     {
//         arr[i+1] = arr[i];
//     }
//     arr[i]=key;
//     return (size+1);
//     }
// }

int main()
{ 
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    for (int i = 0; i < (size-1); i++)
    {
        cin>>arr[i];
    }
    int pos , key;
     cout<<"enter key you want to add: ";
     cin>>key;
     cout<<" enter at which index you want to insert key: ";
     cin>>pos;
     
    // int capacity = sizeof(arr) / sizeof(arr[0]);
    cout<< "\nBefore Insertion: ";
    for (int i = 0; i < size-1; i++)
        cout << arr[i] << " ";
 
    // Inserting key
    size = Insertionatnth(arr, size, key, pos);
 
    cout << "\nAfter Insertion: ";
    for (int i = 0; i < (size-1); i++)
        cout << arr[i]<< " ";
 
 return 0;
}