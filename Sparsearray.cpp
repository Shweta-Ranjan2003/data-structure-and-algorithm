#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
// vector<int> match;
//      for (int i=0; i<queries.size(); i++) {
//          for (int j = 0; j<strings.size(); j++) {
//         if (queries[i]==strings[j]) {
//         match[i]++;
//         }
//          }
//      }
//        return match;  
// }
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
vector<int> result;
int count;
long unsigned int i,j;
for (i=0; i<queries.size(); i++) {
count=0;
j=0;
while (j<strings.size()) {
if (strings[j]==queries[i]) {
 count++;
}
j++;
}
result.push_back(count);
}
return result;
}

int main(){
    int n;
    cin>>n;
    vector<string> strings(n);
    for (int i=0; i<n; i++) {
    cin>>strings[i];
    }
    int q;
    cin>>q;
    vector<string> queries(q);
    for (int i=0; i<q; i++) {
    cin>>queries[i]; 
    };
    vector<int> res = matchingStrings(strings, queries);
    for (int i=0; i<res.size(); i++) {
    cout<<res[i]<<endl;
    }
    return 0;
}