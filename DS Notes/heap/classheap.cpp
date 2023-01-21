#include<iostream>
using namespace std;
int size=100,n=100;
int heap[100];
void insertion(int item,int i)
{
int index=i,pr=i/2;
while(pr>=1)
{
if(heap[pr]<heap[index])
{
int t=heap[pr];
heap[pr]=heap[index];
heap[index]=t;
}
index=pr;
pr=index/2;
}
}
void display()
{
for(int i=1;i<=n;i++)
{
cout<<heap[i]<<endl;
}
}
void deletion()
{{
int item=heap[1];
int last=heap[n];
n--;
int index=1,left=2,right=3;
while(right<=n)
{
if (last>=heap[left] && last>=heap[right])
{
heap[index]=last;
}
if (heap[right]<=heap[left])
{
heap[index]=heap[left];
index=left;
}
else
{
heap[index]=heap[right];
index=right;
}
left=2*index;
right=left+1;
}
left=n;
if(last<heap[left])
{
heap[index]=heap[left];
index=left;
}
heap[index]=last;
return;
}}
int main()
{
while (n>99)
{
cout<<"Enter size of heap less than 100: ";
cin>>n;
}
for(int i=1;i<=n;i++)
{
cout<<"Enter heap element at index "<<i<<" : ";
cin>>heap[i];
insertion(heap[i],i);
}
cout<<"Heap elements are:"<<endl;
display();
cout<<endl;
while(n>0)
{
cout<<"Deletion of "<<heap[1]<<endl;
deletion();
display();
cout<<endl;
}
}