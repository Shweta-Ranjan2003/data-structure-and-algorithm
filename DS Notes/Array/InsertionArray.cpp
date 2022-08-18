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
    int arr[30];
    cout<<"Enter the size of array: ";
    int s;
    cin>>s;
    if (s>=30)
    {
        cout<<"Out of range"<<endl;
    }
    else{
        for (int i = 0; i < s; i++)
        {
            cin>>arr[i];
        }
        
    }
    for (int i = 0; i < s; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter the value you want to insert: ";
    int key , index;
    cin>>key;
    cout<<"Enter the index you want to insert the key: ";
    cin>>index;
    int size = Insertionatnth(arr , s , key , index);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}