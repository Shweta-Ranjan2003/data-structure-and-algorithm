#include <iostream>
#include <string.h>
using namespace std;
/*void reverseArray(int A[] , int size , int start , int end)
{
     int temp=0;
     for (int i =0; i<size/2; i++) {
       temp=A[start];
       A[start]=A[end];
       A[end] = temp;
       start++;
       end--;
     }
}
*/
void reverseArray(int A[] , int size)
{
     int temp=0;
     for (int i =0; i<size/2; i++) {
       temp=A[i];
       A[i]=A[(size-1)-i];
       A[(size-1)-i] = temp;
     }
    
}
int main()
{
    int N;
    cout<<"enter the length of your array:"<<endl;
    cin>>N;
    int A[N];
    cout<<"enter your array "<<endl;
    for (int i=0; i<N; i++) {
    cin>>A[i];
    }
    reverseArray(A,N);
    // reverseArray(A,N,0,(N-1));
    for (int k=0; k<N; k++) {
     cout<<A[k]<<" ";
    }
    return 0;
}


