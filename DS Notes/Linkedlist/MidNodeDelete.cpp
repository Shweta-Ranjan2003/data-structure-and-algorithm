#include <iostream>
using namespace std;
//Delete mid node of a linked list
struct node{
    int data;
    node* next;
};
node* head;

void Insertend(int data){
  node * temp1 = new node();
   temp1->data = data;
   temp1->next= NULL;
   if (!head)
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
void deleteMid(node* head) 
{ 
    if (head == NULL) 
        return; 
    if (head->next == NULL) { 
        delete head; 
        return; 
    } 
    struct node* slow_ptr = head; 
    struct node* fast_ptr = head;     
struct node* prev;  
    while (fast_ptr != NULL  
&& fast_ptr->next != NULL) { 
        fast_ptr = fast_ptr->next->next; 
        prev = slow_ptr; 
        slow_ptr = slow_ptr->next; 
    }  
    prev->next = slow_ptr->next; 
    delete slow_ptr; 
  
    return;
} 
void Print(){
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{ 
 head = NULL;
 int n;
 cin>>n;
for (int i = 0; i < n; i++)
{
    int x;
    cin>>x;
    Insertend(x);
}
deleteMid(head);
Print();
 return 0;
}