#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Unique number -2 
Except 2 numbers every number is repeating 2 times
tell that 2 numbers
5,7,3,2,11,3,5,2
o/p - 7,11

01011 - 11
00111 -  7
------
01100 = 12

If you take any set bit and according to that distribute number into 2 sets
one having that bit set and other having that bit un set
then all duplicates value of a number will present in one set and other in other
but both unique number will be present in different set one in one other in other
because one of them will have bit as set and other unset thats why in xor that bit was set
xor any one set you will find one unique number then xor it will 12 you will get other
*/

void unique2(vector<int>&arr){
int n=arr.size();
int ans=0;
for(int i=0;i<n;i++){
    ans^=arr[i];
}
int temp=ans;
int pos=0;
while(temp>0){
    if((temp&1)!=0){
        break;
    }
    else{
        pos++;
        temp=(temp>>1);
    }
}
int check=0;
for(int i=0;i<n;i++){
    int curr=(arr[i]>>pos);
    if((curr&1)!=0){
        check^=arr[i];
    }
}
cout<<check<<endl;
cout<<(check^ans);
}

int getIthBit(int n ,int i){
    if((n>>i)&1==1)return 1;
    return 0;
}
int setIthBit(int n,int i){
    int temp=1<<i;
    n=n|temp;
    return n;
}
int clearIthBit(int n,int i){
     int temp=~(1<<i);
     n=n&temp;
     return n;
}
int updateIthBit(int n,int i,int bitt){
    if(bitt==1){
        n=setIthBit(n,i);
        return n;
    }
    else{
        n=clearIthBit(n,i);
        return n;
    }
    return n;
}
int countAllSetBit(int n){
    int cnt=0;
    while(n>0){
        n=n&(n-1);
        cnt++;
    }
    return cnt;
}
int clearRangeofBits(int n,int i,int j){
    int no=j-i+1;
    no=pow(2,no)-1;
    int temp=(no<<i);
    temp=~temp;
    n=n&temp;
    return n;
}
int clearRangeofBits2(int n,int j,int i){
   int a=(~0)<<(i+1);
   int b=(1<<j)-1;
   int mask=a|b;
   int ans=n&mask;
   return ans;
   //If we want to insert a no in place of that clear bits then
   //ans=ans|(no<<i);
}

int main()
{ 
 vector<int>arr{5,7,3,2,11,3,5,2};
 //unique2(arr);

 cout<<clearRangeofBits(26,1,2);
 return 0;
}