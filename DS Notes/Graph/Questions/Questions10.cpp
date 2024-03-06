#include <bits/stdc++.h>
using namespace std;
/*

Code
Testcase
Test Result
Test Result
2092. Find All People With Secret
You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

 

Example 1:

Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
Output: [0,1,2,3,5]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
Example 2:

Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
Output: [0,1,3]
Explanation:
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the secret.
At time 3, person 3 shares the secret with person 0 and person 1.
Thus, people 0, 1, and 3 know the secret after all the meetings.
Example 3:

Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
Output: [0,1,2,3,4]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
*/
//Approach-1 (Most basic approach that can come to mind)
//T.C : ~O(M*(M+N)) where M = number of meetings and N = number of people
//S.C : O(M+N)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        map<int, vector<P>> timeMeetings;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            timeMeetings[time].push_back({person1, person2});
        }
        
        vector<bool> knowsSecret(n, false);
        knowsSecret[0]           = true;
        knowsSecret[firstPerson] = true;
        
        //Solve in increasing time meetings
        for(auto &it : timeMeetings) {
            
            int t           = it.first;
            vector<P> meets = it.second;
            
            unordered_map<int, vector<int>> adj;
            queue<int> que;
            unordered_set<int> alreadyAdded;

            for(auto& [person1, person2] : meets) {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);
                
                if(knowsSecret[person1] && alreadyAdded.find(person1) == alreadyAdded.end()) {
                    que.push(person1);
                    alreadyAdded.insert(person1);
                }
                if(knowsSecret[person2] && alreadyAdded.find(person2) == alreadyAdded.end()) {
                    que.push(person2);
                    alreadyAdded.insert(person2);
                }
            }
                
            //Now I know who meet who based on increasing time
            //Let's hit the BFS to spread the secret
            
            while(!que.empty()) {
                int person = que.front();
                que.pop();
                
                for(auto &nextPerson : adj[person]) {
                    if(!knowsSecret[nextPerson]) {
                        knowsSecret[nextPerson] = true;
                        que.push(nextPerson);
                    }
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(knowsSecret[i] == true) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

//Approach-2 (Using BFS Graph Traversal)
//T.C : O(M * (M+N)) -> M = Number of meetings, N = number of people, there can be at most N+M elements in the queue and a person may have M neighbours
//S.C : O(M+N)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }
        
        queue<P> que;
        que.push({0, 0});
        que.push({firstPerson, 0});
        vector<int> earlySecretTime(n, INT_MAX);
        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;
        
        while(!que.empty()) {
            auto [person, time] = que.front();
            
            que.pop();
            
            for(auto& ngbr : adj[person]) {
                int nextPerson = ngbr.first;
                int t          = ngbr.second;
                
                if(t >= time && earlySecretTime[nextPerson] > t) {
                    earlySecretTime[nextPerson] = t;
                    que.push({nextPerson, t});
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(earlySecretTime[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};


//Approach-3 (Using DFS Graph Traversal)
//T.C : O(M * (M+N)) -> M = Number of meetings, N = number of people (Although it's a DFS, but we also revisit some nodes again with better secret knowing time)
//S.C : O(M+N)
class Solution {
public:
    typedef pair<int, int> P;
    
    void dfs(int person, int time, unordered_map<int, vector<P>>& adj, vector<int>& earlySecretTime) {
        for(auto& ngbr : adj[person]) {
            int nextPerson = ngbr.first;
            int t          = ngbr.second;

            if(t >= time && earlySecretTime[nextPerson] > t) {
                earlySecretTime[nextPerson] = t;
                dfs(nextPerson, t, adj, earlySecretTime);
            }
        }
    }
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }

        vector<int> earlySecretTime(n, INT_MAX);
        earlySecretTime[0] = 0;
        earlySecretTime[firstPerson] = 0;

        // Do DFS
        dfs(0, 0, adj, earlySecretTime);
        dfs(firstPerson, 0, adj, earlySecretTime);

        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(earlySecretTime[i] != INT_MAX) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};


//Approach-4 (Using min-heap to fetch earliest time)
//T.C : ~O((N+M) * (log(M+N) + M)) 
//S.C : O(N+M)
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        unordered_map<int, vector<P>> adj;
        
        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time    = meeting[2];
            
            adj[person1].push_back({person2, time});
            adj[person2].push_back({person1, time});
        }
        
        priority_queue<P, vector<P>, greater<P>> pq; //I need the ones first having min time
        pq.push({0, 0});
        pq.push({0, firstPerson});
        
        vector<bool> visited(n, false);
        
        while(!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            
            if(visited[person] == true) {
                continue;
            }
            visited[person] = true;
            
            for(auto& ngbr : adj[person]) {
                int nextPerson = ngbr.first;
                int t          = ngbr.second;
                
                if(t >= time && !visited[nextPerson]) {
                    pq.push({t, nextPerson});
                }
            }
        }
        
        vector<int> result;
        for(int i = 0; i < n; i++) {
            if(visited[i] == true) {
                result.push_back(i);
            }
        }
        
        return result;
    }
int main()
{ 
 
 return 0;
}