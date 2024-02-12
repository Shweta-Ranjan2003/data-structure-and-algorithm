#include <iostream>
#include <vector>
using namespace std;

int recur(int n,vector<int>&ds){
    if(n==0){
        for(auto it: ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return 1;
    }
    if(n<0)return 0;
    
    ds.push_back(1);
    int one=recur(n-1,ds);
    ds.pop_back();

    int two=0;
    if(n>1){
        ds.push_back(2);
        two=recur(n-2,ds);
        ds.pop_back();
    }

    int three=0;
    if(n>2){
        ds.push_back(3);
        three=recur(n-3,ds);
        ds.pop_back();
    }

    return one+two+three;
}
int main()
{ 
 vector<int>ds;
 cout<<recur(4,ds)<<" steps";
 return 0;
}




// int recur(int n,vector<int>&ds){
//     if(n==0){
//         for(auto it: ds){
//             cout<<it<<" ";
//         }
//         cout<<endl;
//         return 1;
//     }
//     if(n<0)return 0;
//     ds.push_back(n-1);
//     int one=recur(n-1,ds);
//     ds.pop_back();
//     int two=0;
//     if(n>1){
//         ds.push_back(n-2);
//         two=recur(n-2,ds);
//         ds.pop_back();
//     }
//     int three=0;
//     if(n>2){
//         ds.push_back(n-3);
//         three=recur(n-3,ds);
//         ds.pop_back();
//     }
//     return one+two+three;
// }