#include <bits/stdc++.h>
using namespace std;
//Binary search is applied in monotonic search space (either increasing or decreasing)
bool check(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1; 
    int last = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
}
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int low=0;
        int high=stalls[n-1]-stalls[0];
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(stalls,mid,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
int main(){

    return 0;
}