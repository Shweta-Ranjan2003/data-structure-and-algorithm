#include <iostream>
using namespace std;

int main()
{ 
 string str;
 cin>>str;
 int leftarrow=0;
 int rightarrow=0;
 int equals=0;
 int n=str.size();
 for(int i=0;i<n;i++){
    if(str[i]=='<')leftarrow++;
    else if(str[i]=='>')rightarrow++;
    else if(str[i]=='=')equals++;
    else {
        cout<<"No";
        return 0;
    }
 }
 if(leftarrow==1 && rightarrow==1 && equals>0){
    cout<<"Yes";
    return 0;
 }
 cout<<"No";
 return 0;
}