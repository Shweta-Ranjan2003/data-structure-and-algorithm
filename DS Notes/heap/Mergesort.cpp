#include <iostream>
using namespace std;
void merge(int a[] , int low , int mid , int high){
    int i=low;
    int j = mid+1;
    int k = low;
    int temp[20];
    while (i<=mid && j<=high)
    {
        if(a[i]<a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k] = a[j];
            j++;
            k++;
        }
        while(i<=mid){
            temp[k] = a[i];
            i++;
            k++;
        }
    }
    
}
void mergesort(int a[] , int low , int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(a , low , mid);
        mergesort( a , mid+1 , high);
        merge(a , low , mid , high);
    }
}
int main()
{ 
    int i;
 int a[0] = {}
 return 0;
}