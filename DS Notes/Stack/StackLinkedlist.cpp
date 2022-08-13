#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
struct Node
{
    int data;
    Node* link;
};
Node* top = NULL;
void Push(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Pop(){
    Node* temp = new Node();
    if (top==NULL)
    {
        return;
    }
    
    temp = top;
    top = top->link;
    delete(temp);
}
void Top(){
    Node* temp ;
    if (top==NULL)
    {
        return;
    }
    
    temp=top;
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
        temp = temp->link;
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

 //Reverse a Linked list
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
        temp=temp->link;
    }
    temp=S.top();
    top=temp;
    S.pop();
    while (!S.empty())
    {
        temp->link=S.top();
        S.pop();
        temp=temp->link;
    }
    
    temp->link=NULL;
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

 //Reverse a Linked list
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