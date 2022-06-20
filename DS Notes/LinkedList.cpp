#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* head;
void Insertfirst(int p){
    node* temp = new node();
    temp->data = p;
    if (head!=NULL)
    { //Sequence of below code matters alot
    temp->next = head; //temp will now point to the same memory address as the head
    head = temp; //now head points to memory address of temp
    }
    head = temp;
    }
void Insertnth(int data , int n){
    node* temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;
    if (n==1)
    {
      temp1->next=head;
      head = temp1;
      return;
    }
    node* temp2 = head;
    for (int i = 0; i < n-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Insertend(int data){
  node * temp1 = new node();
   temp1->data = data;
   temp1->next= NULL;
   if (!head) //if head points to null or list is empty
   {
    head=temp1;
    return;
   }
   node* temp2 = head;
  while (temp2->next)
  {
    temp2 = temp2->next;
  }
  temp2->next = temp1;
   
  
}
void Delete(int n){
 node * temp1 = new node();
 temp1 = head;
 if (n==1)
 {
    head = temp1->next; //head now points to second node
    delete temp1;
    return;
 }
 
 for (int i = 0; i < n-2; i++)
 {
    temp1 = temp1->next;
    //temp1 points to (n-1)th Node
 }
    node* temp2 = temp1->next; //nth node
    temp1->next= temp2->next; //(n+1)th node
    delete temp2;
 
}
node* Reverse(){
    node* current,*prev , *next;
    current = head;
    prev = NULL;
    while (current!=NULL)
    {
        next = current->next;
        current->next=prev;
        prev=current;
        current = next;
    }
    head = prev;
    return head;
}
void Print(){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
//Or
// void Print(node * l){
//     while(l!= NULL){
//         cout<<l->data<<" ";
//         l = l->next;
//     }
// }

int main()
{ 
 head = NULL;
 //For inserting at first position
//   cout<<"how many numbers?"<<endl;
//  int n,x;
//  cin>>n;
// for (int i = 0; i < n; i++)
// {
//     cout<<"enter the no."<<endl;
//     cin>>x;
//     Insertfirst(x);
// }
//     Print();
// cout<<endl;
//For inserting at nth position
//  Insertnth(2,1); //2
//  Insertnth(3,2); //23
//  Insertnth(4,1); //423
//  Insertnth(5,2); //4523
//  Print();
//  cout<<endl;

//For deleting a node at nth position
//  Insertend(2);
//  Insertend(4);
//  Insertend(6);
//  Insertend(5); //2465
//  Print();
//  int nth;
//  cout<<endl;
//  cout<<"Enter a position"<<endl;
//  cin>>nth;
//  Delete(nth);
//  Print();

// Reverse a linked list with iterative meathod
// Insertfirst(2);
// Insertfirst(4);
// Insertfirst(6);
// Insertfirst(8);
// Print();
// cout<<endl;
// head = Reverse();
// Print();

 return 0;
}