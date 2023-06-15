#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* top = NULL;
void Push(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = top;
    top = temp;
}
void Pop(){
    Node* temp=top;
    if (top==NULL)
    {
        return;
    }
    top = temp->next;
    delete(temp);
}
void Top(){
    Node* temp =top;
    if (top==NULL)
    {
        return;
    }
    cout<<temp->data<<endl;
}
int IsEmpty(){
    if (top==NULL)
    {
        return true;
    }
   else return false;
    
}
void Print(){
    Node* temp = top;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
// class Stack{
//     char A[101];
//     int top;
//     public:
//     void Push(int x);
//     void Pop();
//     int Top();
//     bool IsEmpty();
// };
//String reversal using Stack
// void Reverse(char *C,int n){
//     stack<char> S;
//     //Loop for push
//     for (int i = 0; i < n; i++)
//     {
//         S.push(C[i]);
//     }
//     //Loop for pop
//     for (int i = 0; i < n; i++)
//     {
//         C[i]=S.top(); //overwrite the character at index i.
//         S.pop();
//     }
    
// }

 //Reverse a linked list
void REVERSE(){
    if (top==NULL)
    {
        return;
    }
    stack<Node*> S;
    Node* temp=top;
    while (temp!=NULL)
    {
        S.push(temp);
        temp=temp->next;
    }
    temp=S.top();
    top=temp;
    S.pop();
    while (!S.empty())
    {
        temp->next=S.top();
        S.pop();
        temp=temp->next;
    }
    
    temp->next=NULL;
}

int main()
{ 
 Push(2);
 Push(5);
 Push(10);
 Print(); //10 5 2
 Pop();
 Pop();
 Print(); //2
 Top(); //2
 Pop();
 int a = IsEmpty();
 cout<<a<<endl; //1
 Push(10);
 Print(); //10
 int x = IsEmpty();
 cout<<x<<endl; //0
 Pop();

//String reversal using Stack
//  char C[51];
//  cout<<"Enter a string: ";
//  cin>>C;
//  Reverse(C , strlen(C));
//  cout<<"Output= "<<C<<endl;

 //Reverse a linked list
 Push(2);
 Push(5);
 Push(10);
 Push(15);
 Push(20);
 Print();
 REVERSE();
 Print();
 return 0;
}