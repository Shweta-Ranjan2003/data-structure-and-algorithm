#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Merge k-sorted arrays into one
a=[7,8,11,20]
b=[6,10,12,15,28,32]
c=[4,9,13]

o/p=[4,6,7,8,9,10,11,12,13,15,20,28,32]
*/
typedef pair<int, pair<int, int> > ppi;
vector<int> mergeKArrays(vector<vector<int> > arr)
{
    vector<int> output;
 
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
 
    for (int i = 0; i < arr.size(); i++)
        pq.push({ arr[i][0], { i, 0 } });
 
    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();

        int i = curr.second.first;
        int j = curr.second.second;
 
        output.push_back(curr.first);
 
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }
 
    return output;
}
int main()
{
    vector<vector<int> > arr{ { 2, 6, 12 },
                            { 1, 9 },
                            { 23, 34, 90, 2000 } };
 
    vector<int> output = mergeKArrays(arr);
 
    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";
 
    return 0;
}