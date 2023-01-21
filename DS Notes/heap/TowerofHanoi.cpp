#include <iostream>
using namespace std;
void move(int n , char s , char d , char a) //a = auxillary
{
    if(n ==1){
        cout<<"Move disk 1 from rod "<<s<<" to rod "<<d<<endl;
        return;
    }
    move(n-1 , s , a , d);
    cout<<"Move disk "<<n <<" from rod "<<s<<" to rod "<<d<<endl;
    move(n-1 , a ,d ,s);
}
int main()
{ 
 int n;
 cout<<"Enter the number of disks" ;
 cin>>n;
 move(n , 'A' , 'C' , 'B');
 return 0;
}