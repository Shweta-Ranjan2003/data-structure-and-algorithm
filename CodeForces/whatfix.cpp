#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]>=0)ans[i]=1;
        else{
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum>=0){
                    ans[i]=(j-i+1);
                    break;
                }
            }
        }

    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
