#include <iostream>
using namespace std;

class Node {
public:
int data;
Node* next;
Node* previous;
};
Node *head = NULL;
Node *tail = NULL;
void insert(int d) {//insertion at end
Node *n = new Node;
n->data = d;
n->next = NULL;
if(head == NULL) {
head = n;
tail = n;
n->previous=NULL;
}
else {
tail->next = n;
n->previous = tail;
tail = n;
}
}
void traverse(){
cout<<"Traversing in forward direction: ";
Node* ptr = head;
while(ptr!=NULL){
cout<<ptr->data<<" ";
ptr = ptr->next;
}
cout<<"\nTraversing in backward direction: ";
ptr = tail;
while(ptr!=NULL){
cout<<ptr->data<<" ";
ptr = ptr->previous;
}
}
void insertAfterNode(int afterThis, int d) {
Node* n = new Node;
n->data = d;
n->next = NULL;

if(head==NULL)//no node in linked list
head = n;
else if(tail->data == afterThis) {
tail->next = n;
n->previous = tail;
tail = n;
}
else {
Node *ptr = head;
while(ptr!=NULL){
if(ptr->data == afterThis){
n->next = ptr->next;
n->previous = ptr;
ptr->next = n;
(n->next)->previous = n;
}
ptr = ptr->next;
}
}
traverse();
}
void deleteFirstNode() {
if(head == NULL) {
cout<<"Linked list is empty";
}
else {
head = head->next;
head->previous = NULL;
}
}
void deleteLastNode() {
tail = tail->previous;
tail->next = NULL;
}
void deleteAfterNode(int afterThis) {
if(head==NULL)//no node in linked list
cout<<"Underflow";
else {
Node *ptr = head;
while(ptr!=NULL){
if(ptr->data == afterThis){
ptr->next = (ptr->next)->next;
(ptr->next)->previous = ptr;
}
ptr = ptr->next;
}
}
}
int main() {
int ch = 1,x;
while(ch != 0){
cout<<"\nPress:\n1. to insert at the last.\n2. To traverse.\n3. Insert after a node\n4. delete First Node\n5. delete Last Node\n6. delete after Node\n0. to exit.";
cin>>ch;
if(ch == 1) {
cout<<"Enter data to insert at end ";
cin>>x;
insert(x);//end
}
else if(ch == 2)
traverse();
else if(ch == 3) {
int y;
cout<<"After which node?";
cin>>y;
cout<<"Enter new node";
cin>>x;
insertAfterNode(y,x);
}
else if(ch == 4) {
deleteFirstNode();
}
else if(ch == 5) {
deleteLastNode();
}
else if(ch == 6) {
int y;
cout<<"After which node?";
cin>>y;
cout<<"Enter new node";
cin>>x;
insertAfterNode(y,x);
}
}
return 0;
}