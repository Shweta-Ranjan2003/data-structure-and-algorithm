#include <iostream>
#include<queue>
using namespace std;


//Heap is a complete binary tree - max heap means parent is greater than both child and in min heap parent is smaller than both child
//arr[100]
//ind=i  //start from 1 based indexing ****
//left child= i*2;
//right child=i*2+1;
//parent=i/2
//leaf node = n/2+1 to n

// void insert(int arr[] , int size){
//     int parent = size/2;
//     while(parent>1){
//         if(arr[parent]<arr[size]){
//             int temp = arr[parent];
//             arr[parent] = arr[size];
//             arr[size] = temp;
//         }
//         size = parent;
//         parent = size/2;

//     }
//     for (int i = 0; i < 10; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
    
// }

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root Since we are using 0 based indexing
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[],int n){
int size=n;
while(size>1){
    swap(arr[size],arr[1]);
    size--;

    heapify(arr,size,1);
}
}
int main()
{ 
 //We can use Priority queue for both max and min heap
priority_queue<int>pq; //max heap;
pq.push(4);
pq.push(5);
pq.push(9);
cout<<pq.top()<<endl; //9
pq.pop();
cout<<pq.top()<<endl; //5

priority_queue<int,vector<int>,greater<int>> mh;
mh.push(9);
mh.push(4);
mh.push(5);
cout<<mh.top()<<endl; //4
mh.pop();
cout<<mh.top()<<endl; //5
 return 0;
}