#include <iostream>
using namespace std;
// void insert(int arr[] , int size){
//     int N = size/2;
//     while(N>1){
//         if(arr[N]<arr[size]){
//             int temp = arr[N];
//             arr[N] = arr[size];
//             arr[size] = temp;
//         }
//         size = N;
//         N = size/2;

//     }
//     for (int i = 0; i < 10; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
// }
int main()
{ 
    int n,s;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the no. of elements in heap: ";
    cin>>s;
    while (s>n)
{
cout<<"Heap size is greater than array size";
cout<<"Please enter again less than "<<n;
cin>>s;
}
cout<<"Enter heap element: ";
for(int i=1;i<=s;i++)
{
cin>>arr[i];
}

if(s==n)
{
cout<<"Array is full you cannot insert element in it";
}
else
{
s++;
cout<<"Enter elment to insert in heap: ";
cin>>arr[s];
// insert(arr,s);
int ptr,pr;
ptr=s;
pr=ptr/2;
while(pr!=0)
{
if(arr[pr]<arr[ptr])
{
int t=arr[pr];
arr[pr]=arr[ptr];
arr[ptr]=t;

}
ptr=pr;
pr=ptr/2;
}
for(int i=1;i<=s;i++)
{
cout<<arr[i]<<" ";
}
}
 
 return 0;
}