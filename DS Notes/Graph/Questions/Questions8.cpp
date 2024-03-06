#include <bits/stdc++.h>
using namespace std;
/*
1514. Path with Maximum Probability
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
*/
  typedef pair<double, int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        vector<double> result(n, 0);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<P> pq; //max heap because we need maximum probability

		result[start] = 1;
		pq.push({1.0, start});

		while(!pq.empty()) {

		    int curnode    = pq.top().second;
            double curProb = pq.top().first;
            pq.pop();

            for(auto &child : adj[curnode])
            {
                if(result[child.first] < curProb*child.second) //we want maximum this time
                {
                    result[child.first] = curProb*child.second;
                    pq.push({result[child.first], child.first});
                }
            }

		}

		return result[end];

    }

/*
332. Reconstruct Itinerary
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
*/

 unordered_map<string, vector<string>> adj;
    vector<string> route;
    int numTickets = 0;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		numTickets = tickets.size();
        
		for (auto& t : tickets) {
            string u = t[0];
            string v = t[1];
            
			adj[u].push_back(v);
		}
        
        // Sort vertices in the adjacency list by lexical order
        for (auto &edges : adj) {
            sort(begin(edges.second), end(edges.second));
        }
        
        vector<string> temp;
        DFS("JFK", temp);
        return route;
    }
    
    bool DFS(string fromAirport, vector<string>& temp) {
        temp.push_back(fromAirport);
        
        // we have used all tickets, this is a valid path return the result
        if (temp.size() == numTickets+1) {
            route = temp;
            return true;
        }
        
        //You have already found the route (first valid lexicographically path)
        vector<string>& neighbors = adj[fromAirport];
        
        // at the current layer, try its neighbors in the sorted order
        for(int i = 0; i < neighbors.size(); i++) {
            
            string toAirport = neighbors[i];
            
            // remove ticket(route) from graph so that it won't be reused 
            neighbors.erase(neighbors.begin()+i);
            
            if(DFS(toAirport, temp))
                return true;
            
            // if the current path is invalid, restore the current ticket
            neighbors.insert(neighbors.begin()+i, toAirport);            
        }
        
        temp.pop_back();
        return false;
    }


/*
847. Shortest Path Visiting All Nodes
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3]

*/
typedef pair<int, int> P;
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        if(n == 1 || n == 0)
            return 0;
        
        queue<P> que;
        
        set<P> vis;
        //Instead of set, you can also use : vector<vector<bool>> visited(n, vector<bool>(finalState, false));
        //Just like done in Java code below

        int allVisitedState = (1 << n) - 1; // if all nodes visited then
            
        for(int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            
            que.push({i, maskValue});
            
            vis.insert({i, maskValue});
        }
        
        int result = 0;
        
        // Implementing BFS
        while(!que.empty())  {
            
            int N = que.size();
            result++;
            while(N--) {
                
                auto curr = que.front();
                que.pop();
                
                int currNode = curr.first;
                int currMask = curr.second;
                
                for(auto &adj: graph[currNode]) {
                    int nextMask = currMask | (1 << adj);
                    
                    if(nextMask == allVisitedState)
                        return result;
                    
                    if(vis.find({adj, nextMask}) == vis.end()) {
                        vis.insert({adj, nextMask});
                        que.push({adj, nextMask});                      
                    }
                }  
            }
        }

        return -1;
    }
int main()
{ 
 
 return 0;
}