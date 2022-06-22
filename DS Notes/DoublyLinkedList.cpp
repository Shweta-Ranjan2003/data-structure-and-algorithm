#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
Node* Head;
Node* GetNewNode(int x){
    Node* newNode= new Node();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next=NULL;
    return newNode;
}
void InsertAtHead(int x){
    Node* NewNode = GetNewNode(x);
    if (Head == NULL)
    {
        Head = NewNode;
        return;
    }
    Head->prev = NewNode;
    NewNode->next = Head;
    Head = NewNode;
    
}
void InsertAtTail(int y){
     Node* NewNode = GetNewNode(y);
     Node* temp = Head;
     while (temp->next!=NULL)
     {
        temp=temp->next;
     }
     NewNode->prev=temp;
     temp->next=NewNode;
}
void Print(){
Node* temp = Head;
cout<<"Forward: "<<" ";
while (temp!=NULL)
{
    cout<<temp->data<<" ";
    temp=temp->next;
}

}
void ReversePrint(){
     Node* temp = Head;
     if (temp==NULL) 
     {
        return;
     }
     while (temp->next!=NULL)
     {
        temp= temp->next;
     }
     //Traversing backward using prev pointer
     cout<<"Reverse: "<<" ";
     while (temp!=NULL)
     {
        cout<<temp->data<<" ";
        temp=temp->prev;
     }
     
     
}
int main()
{   Head = NULL;
    InsertAtHead(2); 
    InsertAtHead(4);
    InsertAtHead(6); 
    Print(); //642
    ReversePrint(); //246
    InsertAtTail(0);
    InsertAtTail(-2);
    Print();
    ReversePrint();
 
 return 0;
}