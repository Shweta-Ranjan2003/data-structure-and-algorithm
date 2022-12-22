#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
 Node* front = NULL;
 Node* rear = NULL;
void insert(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (front==NULL && rear==NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void Delete(){
    Node* temp = front;
    if (front == NULL)
    {
        return;
    }
    if (front ==rear)
    {
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    delete(temp);
}
void print(){
    Node* temp = front;
    if(front == NULL){
        return;
    }
    while(temp!=NULL){
        cout<<temp->data;
        temp = temp->next;
    }
}
int main()
{ 
    int x=1;
    int data;
    while(x!=0){
    cout<<"Press 1 for Insertion \nPress 2 for Deletion \n0 to exit";
    cin>>x;
    if (x==1)
    {
        cout<<"Enter data you want to insert"<<endl;
        cin>>data;
        insert(data);
    }
    else if(x==2){
        Delete();
    }
    }
     print();
 return 0;
}