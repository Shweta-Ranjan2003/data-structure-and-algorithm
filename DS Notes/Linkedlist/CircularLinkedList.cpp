#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
node* head = NULL;
void traverse(){
    node* ptr;
    ptr = head;
    do
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    } while (ptr!=head);
    
}
void insert(int d){
    node* ptr;
    node* n = new node;
    n->data = d;
    n->next = NULL;
    if (head==NULL)
    {
        head = n;
        n->next = head;
    }
    else{
        ptr = head;
        while(ptr->next!=head){
            ptr = ptr->next;
        }
        ptr->next = n;
        n->next = head;
    }
}
int main()
{ 
    int ch = 1 ,x;
    while (ch!=0)
    {
        cout<<"\nPress:\n1. To insert at the last.\n2. To traverse.\n0. to exit."<<endl;
        cin>>ch;
        if(ch==1){
            cin>>x;
            insert(x);
        }
        else if(ch==2){
            traverse();
        }
    }
    
 
 return 0;
}