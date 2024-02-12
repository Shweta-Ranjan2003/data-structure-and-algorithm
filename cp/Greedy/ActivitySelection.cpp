#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
BUSY MAN - spoj
n-meeting - lc
*/
class activity{
    public:
    int s;
    int e;
    string nm;
    activity(int i , int j, string name){
        s=i;
        e=j;
        nm=name;
    }
};
bool cmp(activity a,activity b){
    return a.e<b.e;
}
int main()
{ 
 vector<activity>ans;
 activity a(6,8,"yoga");
 activity b(8,10,"Breakfast");
 activity c(9,13,"class");
 activity d(11,12,"chai");
 activity e(13,15,"college");
 activity f(14,16,"sleep");
 activity g(16,18,"sports");
 activity h(17,19,"gym");
 ans.push_back(a);
 ans.push_back(b);
 ans.push_back(c);
 ans.push_back(d);
 ans.push_back(e);
 ans.push_back(f);
 ans.push_back(g);
 ans.push_back(h);
 sort(ans.begin(),ans.end(),cmp);
 int n=ans.size();
 int cnt=1;
 int last=a.e;
 for(int i=1;i<n;i++){
    if(ans[i].s>=last){
        cnt++;
        last=ans[i].e;
    }
 }
 cout<<cnt;
 return 0;
}