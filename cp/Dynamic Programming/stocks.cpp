#include <iostream>
using namespace std;
/*
Best time to buy and sell stocks
7 , 1 , 5 , 3 , 6 , 4
buy and sell only once and maximize the profit

 int maxProfit(vector<int>& prices) {
           int buy = prices[0], max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
        if (buy > prices[i])
            buy = prices[i];
        else if (prices[i] - buy > max_profit)
            max_profit = prices[i] - buy;
        }
        return max_profit;
        }
        
*/

/*
Best time to buy and sell stock 2
7 , 1 , 5 , 3 , 6 , 4
you can buy and sell as many times we want but you can not hold more then one stock at a time

try all possible ways 
at any time lets say at ind=2 (5) if we will buy then we will have profit of -price[2];
and if we sell at ind=4 (6) then profit which was earlier -5 will add to 6 and become 1;
 
// 1 , 2 , 5 , 6 
f(ind,can_buy){
    if(ind==n) return 0;

    if(buy){
        profit=max((-prices[ind] + f(ind+1,0)),  //take
        0+f(ind+1,1));  //not take
    }
    else{
    profit = max((prices[ind]+f(ind+1,1)) ,
             0+f(ind+1,0));
    }
    return profit;
}


//Memoization
dp[n][2]=-1
f(ind , buy , values , n){
    if(ind==n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    long profit=0;
    if(buy){
        profit=max(-values[ind]+f(ind+1,0) , 0+f(ind+1,1));
    }
    else{
        profit=max(values[ind]+f(ind+1,1), 0+f(ind+1,0));
    }
    return dp[ind][buy]= profit;
}

//Tabulation
dp[n+1][2];

dp[n][0]=dp[n][1]=0;
for(int i=n-1;i>=0;i--){
    for(int buy=0;buy<=1;buy++){
        long profit=0;
        if(buy){
            profit=max(-values[i]+dp[i+1][0] , 0+dp[i+1][1]);
        }
        else{
            profit=max(values[i]+dp[i+1][1] , 0+dp[i+1][0]);
        }
        dp[i][buy]=profit;
    }
}
return dp[0][1];

//Space optimization
vector<long>ahead(2,0) , curr(2,0);
ahead[0]=ahead[1]=0;

for(int i=n-1;i>=0;i--){
    for(int buy=0;buy<=1;buy++){
        long profit=0;
        if(buy){
            profit=max(-values[i]+ahead[0] , 0+ahead[1]);
        }
        else{
            profit=max(values[i]+ahead[1] , 0+ahead[0]);
        }
        curr[buy]=profit;
    }
    ahead=curr;
}
return ahead[1];
*/

/*
Buy and sell stock 3 
at max two transaction

prices = [3, 3, 5, 0, 0, 3, 1, 4]

f(ind , buy , cap){
if(ind==n || cap==0) return 0;

    if(buy){
        return max(-prices[ind]+f(ind+1,0,cap) , 
        //if we buy we will have profit of -price[element] and we will call recur for ind+1 but will buy value 0 which means now we cannot buy again
                0+f(ind+1,1,cap));
        //if we not buy then ind+1 and buy=1 which means you are allowed to buy next day
    }
    else{
        return max(prices[ind]+f(ind+1,1,cap-1),
                    0+f(ind+1,0,cap));
    }
}

//Memoization
dp[n][2][3]=-1;
int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

    if(ind==n || cap==0) return 0; //base case
    
    if(dp[ind][buy][cap]!=-1)
        return dp[ind][buy][cap];
        
    int profit;
    
    if(buy){
        profit = max(0+getAns(Arr,n,ind+1,1,cap,dp), 
                    -Arr[ind] + getAns(Arr,n,ind+1,0,cap,dp));
    }
    
    else{
        profit = max(0+getAns(Arr,n,ind+1,0,cap,dp),
                    Arr[ind] + getAns(Arr,n,ind+1,1,cap-1,dp)); //transactions get completed only after sell so when selled then call recursion with cap-1;
    }
    
    return dp[ind][buy][cap] = profit;
}


//Tabulation
if cap =0 the ind,buy can be anything
for(int i=0;i<n;i++){
for(int b=0;b<=1;b++){
    dp[i][b][0]=0;
}
}
for(int b=0;b<=1;b++){
for(int c=0;c<=2;c++){
    dp[n][b][c]=0;
}
}
//after the base case just start from the opposite of memoization
//then copy the recurrence;


vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

for(int ind=n-1;ind>=0;ind--){
    for(int buy=0;buy<=1;buy++){
        for(int cap=1;cap<=2;cap++){
        
    if(buy){
        dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],
                              0+dp[ind+1][1][cap]);
    }
    else{
        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],
                              0+dp[ind+1][0][cap]);
    }
        }
    }
}
  return  dp[0][1][2];


//Space optimization
  vector<vector<int>> ahead(2,vector<int> (3,0));
    
    vector<vector<int>> cur(2,vector<int> (3,0));
    
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy = 0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                
                if(buy==0){// We can buy the stock
                    cur[buy][cap] = max(0+ahead[0][cap], 
                                -Arr[ind] + ahead[1][cap]);
                 }
    
                if(buy==1){// We can sell the stock
                    cur[buy][cap] = max(0+ahead[1][cap],
                                Arr[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = cur;
    }
    
    return ahead[0][2];
*/

/*
Buy and sell stocks 4 
at most k transaction - same as 3rd just use k as a cap instead of 2
(One more way left in video to watch)
int recur(int ind,vector<int>&prices,int buy,int cap,vector<vector<vector<int>>>&dp){
    if(ind==prices.size() or cap==0) return 0;
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
 
    if(buy){
     return dp[ind][buy][cap]=max(-prices[ind]+recur(ind+1,prices,0,cap,dp),
                               0+recur(ind+1,prices,1,cap,dp));
    }
    else{
        return dp[ind][buy][cap]=max(prices[ind]+recur(ind+1,prices,1,cap-1,dp),
                                    0+recur(ind+1,prices,0,cap,dp));
    }
}
*/

/*
Best time to buy and sell stocks with cooldown(cannot buy right after sell)
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Input: prices = [1,2,3,0,2]
Output: 3

just after sell call recursion for ind+2 instead of ind+1
dp[n][2];
f(ind,buy){
    if(ind>=prices.size())return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    if(buy){
        return dp[ind][buy]=max(-prices[ind]+f(ind+1,0),
                  0+f(ind+1,1));
    }
    return dp[ind][buy]=max(prices[ind]+f(ind+2,1),
               0+f(ind+1,0));
}

//Tabulation
 vector<vector<int>> dp(n+2,vector<int>(2,0));
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit;
            
            if(buy==0){// We can buy the stock
                profit = max(0+dp[ind+1][0], -Arr[ind] + dp[ind+1][1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+dp[ind+1][1], Arr[ind] + dp[ind+2][0]);
            }
            
            dp[ind][buy] = profit;
        }
    }
    
    return dp[0][0];

//Space optimization
int n = Arr.size();
    vector<int> cur(2,0);
    vector<int> front1(2,0);
    vector<int> front2(2,0);
    
    for(int ind = n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            int profit;
            
            if(buy==0){// We can buy the stock
                profit = max(0+front1[0], -Arr[ind] + front1[1]);
            }
    
            if(buy==1){// We can sell the stock
                profit = max(0+front1[1], Arr[ind] + front2[0]);
            }
            
            cur[buy] = profit;
        }
        
        front2 = front1;
        front1 = cur;
        
    }
    
    return cur[0];
*/

/*
Best Time to Buy and Sell Stock with Transaction Fee
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
//add  transaction fee at time of buy or sell any one time

f(ind,can_buy){
    if(ind==n) return 0;

    if(buy){
        return profit=max((-prices[ind] + f(ind+1,0)),  //take
        0+f(ind+1,1));  //not take
    }
    else{
   return  profit = max((prices[ind]-fee+f(ind+1,1)) ,
             0+f(ind+1,0));
    }
}

//Tabulation
  int n=prices.size();
       vector<vector<int>>dp(n+1,vector<int>(2,0));
// dp[n][0]=dp[n][1]=0; (already 0)
for(int i=n-1;i>=0;i--){
    for(int buy=0;buy<=1;buy++){
        long profit=0;
        if(buy){
            profit=max(-prices[i]+dp[i+1][0] , 0+dp[i+1][1]);
        }
        else{
            profit=max(prices[i]-fee+dp[i+1][1] , 0+dp[i+1][0]);
        }
        dp[i][buy]=profit;
    }
}
return dp[0][1];
*/
int main()
{ 
 
 return 0;
}