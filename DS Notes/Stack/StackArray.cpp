#include <iostream>
#define MAX_SIZE 101
using namespace std;
/*
Stack ADT(last-in-first-out LIFO):- A list with the restriction that insertion and deletion
can be performed only from one end , called the top.
Operations(main):- push(x), pop() , top() , isempty() (Constant time operations O(1))
We can implement stacks using:- Arrays , linked list.
Array implementation:- int A[10]; top<--1; 
Push(x){ top<-top+1; A[top]<-x}
Pop(){ top<- top-1;}
Top(){return A[top];}
IsEmpty(){if(top==-1)return true; else return false;}
*/
int A[MAX_SIZE];
int top=-1;
void Push(int x){
    if(top== MAX_SIZE -1){ 
        cout<<"Error: stack overflow "<<endl;
        return;
    }
    A[++top] = x;
}
void Pop(){
    if (top==-1)
    {
        cout<<"Error: No element to pop"<<endl;
        return;
    }
    
    top--;
}
int Top(){
    return A[top];
    }
int IsEmpty(){
    if(top==-1)
    return true; 
    else 
    return false;
    }
void Print(){
    int i;
    cout<<"Stack: ";
    for (int i = 0; i <=top; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    
}
int main()
{ 
    Push(2);
    Push(4);
    Push(10);
    Print();
    Pop();
    Print();
    int x = Top();
    cout<<x<<endl;
    int y=IsEmpty();
    cout<<y<<endl;
 
 return 0;
}