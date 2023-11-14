#include <iostream>
using namespace std;
/*
Shortest path in undirected graph with unit weights
in adj matrix we will store pair (node,weight);

Step 1- Do a topo sort on the graph
Step 2- Take the node out of stack and relax the edge

maintain a distance vector of infinity then relax it by taking edges one by one

void topoSort(int node, vector < pair < int, int >> adj[],int vis[], stack < int > & st) { 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }

vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

      //We create a graph first in the form of an adjacency list.
      vector < pair < int, int >> adj[N];
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      // A visited array is created with initially 
      // all the nodes marked as unvisited (0).
      int vis[N] = {0};
      //Now, we perform topo sort using DFS technique 
      //and store the result in the stack st.
      stack < int > st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
      //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
      //distance from the source vertex after relaxation of a particular node.

      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
*/

/*
Shortest path in undirected graph with unit weights -BFS
all the edges have unit dist - why queue because here all the nodes will be sorted
like first node with weight 1 then of 2 and so on , so they are already stored in sorted manner

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    //Create an adjacency list of size N for storing the undirected graph.
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        //A dist array of size N initialised with a large number to 
        //indicate that initially all the nodes are untraversed.    
    
        int dist[N];
        for(int i = 0;i<N;i++) dist[i] = 1e9;
        // BFS Implementation.
        dist[src] = 0; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        // Updated shortest distances are stored in the resultant array ‘ans’.
        // Unreachable nodes are marked as -1. 
        vector<int> ans(N, -1);
        for(int i = 0;i<N;i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }
        return ans; 
    }
*/

/*
Word Ladder 1
shortest Transformation sequence by changing only one letter at a time by begin word to end word
beginword="hit" endword="log"
wordlist=[hot,dot,dog,lot,log,log]

hit - hot - dot - dog - log
transformation - 4
sequence length-5

hit  - 1
hot  - 2
dot lot  - 3
-- -- --   - 4
--------   - 5   (shortest sequence) we are following bfs

int wordLadderLength(string startWord, string targetWord,vector<string> &wordList)
    {
    // Creating a queue ds of type {word,transitions to reach ‘word’}.
        queue<pair<string, int>> q;

        // BFS traversal with pushing values in queue 
        // when after a transformation, a word is found in wordList.
        q.push({startWord, 1});

        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // we return the steps as soon as
            // the first occurence of targetWord is found.
            if (word == targetWord)
                return steps;

            for (int i = 0; i < word.size(); i++)
            {
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    // check if it exists in the set and push it in the queue.
                    if (st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        // If there is no transformation sequence possible
        return 0;
    }
*/

/*
Word ladder 2
Same but you have to return the list of transformation sequence and all the sequences of smallest length
starting word = bat , ending word = coz
word list - {pat,bat,pot,poz,coz}

{bat}

{bat , pat}
{bat , bot}
erase lvl 1 (bat)

{bat,pat,pot}
{bat,bot,pot}  //Do not erase pot till level 3 is completed see here we got pot 2 times this couldnt happen if you erase it 
erase lvl 2


{bat,pat,pot,poz}
{bat,bot,pot,poz}
erase lvl 3

{bat,pat,pot,poz,coz}
{bat,bot,pot,poz,coz}
erase lvl 4

coz is ending word so return 5 size list and put both answer to it

unordered_set<string>st(wordlist.begin(),wordlist.end());
queue<vector<string>>q;
q.push({beginword});
vector<string>used;
used.push_back(beginword);
int lvl=0;
vector<vector<string>>ans;
while(!q.empty()){
  vector<string>vec=q.front();
  q.pop();
  if(vec.size()>lvl){
    lvl++;
    for(auto it:used){
      st.erase(it);
    }
    used.clear();
  }
  string word=vec.back();
  if(word==endword){
    if(ans.size()==0){
      ans.push_back(vec);
    }
    else if(ans[0].size()==vec.size()){
      ans.push_back(vec);
    }
  }
  for(int i=0;i<word.size();i++){
    char org=word[i];
    for(chat c='a' ; c<='z';c++){
      word[i]=c;
      if(st.count(word)>0){
        vec.push_back(word);
        q.push_back(vec);
        used.push_back(word);
        vec.pop_back();
      }
    }
    word[i]=org;
  }
}
*/

/*
Word ladder 2 - optimized approach  - not understand - 31 video
step 1- follow ladder and store the steps
step 2- backtrack in the map from end to begin to get the answer
store in map
hit-0
hot-1
dot-2
lot-2
dog-3
log-3
cog-4


dfs(log,{cog,log})                   dfs(dog,{cog,dog})  possible because 4-3
not dfs(dog,{log,dog}) because 3,3
dfs(lot,{cog,log,lot})
dfs(hot,{cog,log,lot,hot})
dfs(hit,{cog,log,lot,hot,hit})

then execute other one
 // Create a map of type word->level to get the idea 
    // on which level the word comes after the transformations.
    unordered_map<string, int> mpp;

    // A vector for storing the final answer.
    vector<vector<string>> ans;
    string b;

    void dfs(string word, vector<string> &seq)
    {
        // Function for implementing backtracking using the created map
        // in reverse order to find the transformation sequence in less time.

        // Base condition :
        // If word equals beginWord, we’ve found one of the sequences
        // simply reverse the sequence and return. 
        if (word == b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
    
            // reverse again so that the dfs calls are not disturbed.
            reverse(seq.begin(), seq.end());
            return;
        }
        int sz = word.size();
        int steps = mpp[word];

        // Replace each character of the word with letters from a-z 
        // and check whether the transformed word is present in the map
        // and at the previous level or not.  
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] + 1 == steps)
                {
                    seq.push_back(word);
                    dfs(word, seq);
                    // pop the current word from the back of the queue
                    // to traverse other possibilities.
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
*/
int main()
{ 
 
 return 0;
}