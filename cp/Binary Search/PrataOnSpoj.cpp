#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
IEEE is having its AGM next week and the president wants to serve 
cheese prata after the meeting. The subcommittee members are asked 
to go to food connection and get P (P<=1000) pratas packed for the 
function. The stall has L cooks (L<=50) and each cook has a rank R 
(1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 
1 more prata in the next 2R minutes, 1 more prata in 3R minutes and 
so on (he can only cook a complete prata) (For example if a cook is 
ranked 2, he will cook one prata in 2 minutes one more prata in the 
next 4 mins an one more in the next 6 minutes hence in total 12 minutes 
he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he 
does not have enough time for the 4th prata). 
The webmaster wants to know the minimum time to get the order done.
10 - prata
4  - cooks
1 2 3 4 - ranks
8 - o/p
*/
bool check(vector<int>&ranks,int time,int prata){
    int total=0;
    for(int cook: ranks){
        int cnt=0;
        int rank=cook;
        int ctime=0;
        while(ctime+(cnt+1)*rank <= time){
            cnt++;
            ctime=ctime+(cnt*rank);
        }
        total=total+cnt;
    }
    return total>=prata;
}
int main()
{ 
    int prata=10;
    vector<int>ranks{4,1,2,3,4};
    int cooks=ranks.size();
    int low=0;
    int high=INT_MAX;
    for(int i=0;i<cooks;i++){
        high=min(high,ranks[i]);
    }
    high=high*(prata*(prata+1))/2;
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(ranks,mid,prata)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        cout<<ans;
 return 0;
}