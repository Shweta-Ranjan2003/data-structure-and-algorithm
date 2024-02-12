#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;
/*
Leetcode 239
1. Given a window size k , print max element of all window of size k in an given array
k=3
1 3 2 4 6 1 4 2 7
3 4 6 6 6 4 7

- N*k complexity -> Traverse through every k sized window to check for its maximum
- N -> use deque
- NLogN -> use multiset it is sorted , push element it will auto sort it use
           *mst.rbegin() to dereference last element and remove the first element when 
           moving forward find mst.find(i) and remove it maintain i pointer at begin and
           move it
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1)return nums;
        vector<int>ans;
        deque<int>dq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            //contract from front
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            //expand from end
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
}

vector<int> maxSlidingWindow2(vector<int>&nums,int k){
    multiset<int>mst;
    int n=nums.size();
    vector<int>ans;
    for(int i=0;i<k;i++){
        mst.insert(nums[i]);
    }
    int s=0;
    multiset<int>::iterator it;
    for(int i=k;i<n;i++){
        ans.push_back(*mst.rbegin());
        it=mst.find(nums[s]);
        s++;
        mst.erase(it);
        mst.insert(nums[i]);
    }
    ans.push_back(*mst.rbegin());
    return ans;
}

/*
Find the Smallest number (Not leading Zeros) which can be obtained by rearranging the digits of a given number. 
Examples: 
Input: n = 846903
Output: 304689
Input: n = -40505
Output: -55400
*/
int smallest(int num)
{
    int freq[10] = {0};
    bool is_pos = (num>0);
    num = abs(num);
    while (num)
    {
        int d = num % 10; 
        freq[d]++; 
        num = num / 10; 
    }
     
    int result = 0;
      if(is_pos) 
    {
      for (int i = 1 ; i <= 9 ; i++)
      {
          if (freq[i])
          {
              result = i;
              freq[i]--;
              break;
          }
      }

      for (int i = 0 ; i <= 9 ; i++)
          while (freq[i]--)
              result = result * 10 + i;
    }
    else
    {
      for (int i = 9 ; i >= 1 ; i--)
      {
         if (freq[i])
         {
            result = i;
            freq[i]--;
            break;
         }
      }

      for (int i = 9 ; i >=0 ; i--)
         while (freq[i]--)
            result = result * 10 + i;
      result = -result; 
    }
    return result;
}

//Same code with few changes for find the largest number by rearranging the digits

/*
using given no. return kth smallest no. possible
1,5,7
1 5 7 11 15 17 51 55 57 71 75 77 111...
return 55 if k=8
*/
int main()
{ 
 
 return 0;
}