#include <iostream>
#include <vector>
using namespace std;
/*
Given array and you are given q queries you have to return sum of even indexes in range L to R 
for every query
runs - 5 3 8  4  6  10 2
csum - 5 5 13 13 19 19 21
*/
// int evenSum(int arr[],int L , int R){
//     int n=arr.size();
//     int csum[n];
//     csum[0]=arr[0];
//     for(int i=1;i<n;i++){
//         if(i%2!=0) csum[i]=csum[i-1];
//         else csum[i]=csum[i-1]+arr[i];
//     }

//     if(L==0) return csum[R];
//     else return csum[R]-csum[L-1];
// }

//Equilibrium index - sum of elements on left == sum of elements on right
// int eq(int arr[],int L , int R){
//     int n=arr.size();
//     int csum[n];
//     csum[0]=arr[0];
//     for(int i=1;i<n;i++){
//         csum[i]=csum[i-1]+arr[i];
//     }
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         int left=0;
//         int right=0;
//         if(i!=0){
//             left=csum[i-1]; //sum of elements on left
//         }
//         right=csum[n-1]-csum[i]; //sum of elements on right
//         if(left==right) cnt++;
//     }
//     return cnt;
//     //We can also optimize space by first calculating total sum and then at 
//     //every index checking for its half to get index .
// }


//****1664 leetcode*****
//Count no of special index - index after removing this index 
//sum of even indexed element == sum of all odd indexed element
// if you remove 1st index then 0 will be counted in even but after removing 1th index all index
//will left shift so odd becomes even and even becomes odd
int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int>odd(n,0);
        vector<int>even(n,0);
        even[0]=nums[0];
        for(int i=1;i<n;i++){
         if(i%2==0){
            odd[i]=odd[i-1];
            even[i]=nums[i]+even[i-1];
         }
         else{
            even[i]=even[i-1];
            odd[i]=nums[i]+odd[i-1];
         }
        }
        int cnt=0;
        int i=0;
        int evensum=odd[n-1]-odd[i];
        int oddsum=even[n-1]-even[i];
        if(evensum==oddsum) cnt++;
        for(i=1;i<n;i++){
            int evensum=even[i-1]+(odd[n-1]-odd[i]);
            int oddsum=odd[i-1]+(even[n-1]-even[i]);
            if(evensum==oddsum)cnt++;
        }
        return cnt;
    }

/*
Ramu wants to divide the field so that he gets max no mangoes assuming
sistas will pick best 3 rectangle
*/
int Ram(vector<vector<int>>&mango){
    int n=mango.size();
    vector<vector<int>>prefix(n,vector<int>(n,0));
    prefix[0][0]=mango[0][0];
    for(int i=1;i<n;i++){
        prefix[i][0]=prefix[i-1][0]+mango[i][0];
        prefix[0][i]=prefix[0][i-1]+mango[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            prefix[i][j]=mango[i][j]+(prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1]);
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
           int q1=prefix[i][j];
           int q2=prefix[i][n-1]-q1;
           int q3=prefix[n-1][j]-q1;
           int q4=prefix[n-1][n-1]-(q1+q2+q3);
           ans=max(ans,min(q1,min(q2,min(q3,q4))));
        }
    }
    return ans;
}
int main()
{ 
 vector<vector<int>>mango{{1,2,3,1},{2,6,4,8},{1,3,2,7},{2,0,1,5}};
 cout<<Ram(mango);
 return 0;
}