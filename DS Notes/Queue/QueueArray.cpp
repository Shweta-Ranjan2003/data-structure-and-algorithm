#include <iostream>
using namespace std;
/*
CIRCULAR ARRAY:- Current position =i
                 Next position = (i+1)%N (where N is total no. of elements in array)
                 Previous position = (i+N-1)%N

Queue - First-in-First-out(FIFO):- A list or collection with the restriction
that insertion can be performed at one end(rear) and deletion can be performed at other end(front).

Operation:- 1. Enqueue(x) or Push(x) 2. Dequeue or Pop().
2. front() or peek() 4. Isempty() 
- ALl Constant time( O(1))

//Array Implementation
int A[10]
front= -1
rear = -1
IsEmpty(){ if front==-1 && rear==-1 return true else return false}

Enqueue(x){if (rear+1)%N==front return 
        else if IsEmpty(){
            front=rear=0
        } else {rear= (rear+1)%N}
        A[rear]=x
}
Dequeue(){
    if IsEmpty() return
    else if front==rear
    front=rear=-1
    else front=(front+1)%N
}
front(){return A[front]}
*/

int main()
{ 
 
 return 0;
}