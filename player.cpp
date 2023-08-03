#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> players(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> players[i][j];
        }
    }
    
    int playerOfYear = 0;
    int longestTopDuration = 0;
    
    for (int i = 0; i < n; i++) {
        int topDuration = 0;
        
        for (int j = 0; j < m; j++) {
            bool isTop = true;
            
            for (int k = 0; k < n; k++) {
                if (playerData[i][j] < playerData[k][j]) {
                    isTop = false;
                    break;
                }
            }
            
            if (isTop) {
                topDuration++;
            }
        }
        
        if (topDuration > longestTopDuration) {
            longestTopDuration = topDuration;
            playerOfYear = i;
        }
    }
    
    cout << playerOfYear << endl;
    
    return 0;
}