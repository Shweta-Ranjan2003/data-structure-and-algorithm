#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Form the largest number
[1,33,332]
Then largest will be 33 332 1
We can use sorting will comparator func by checking whether a+b is giving bigger result
or b+a

1 + 33 = 133 or 33 + 1 = 331
then 33 + 332 = 33332 or 332 + 33 = 33233
1 + 33332 = 133332 or 33332 + 1 = 333321
*/
bool comp(int x , int y){
    string a=to_string(x);
    string b=to_string(y);
    return a+b > b+a;
}
int main()
{ 
 //vector<int>arr{1,33,332};
 //vector<int>arr{0,00,0001};
 vector<int>arr{0,00,59};
 sort(arr.begin(),arr.end(),comp);
 for(auto it:arr){
    cout<<to_string(it);
 }
 return 0;
}