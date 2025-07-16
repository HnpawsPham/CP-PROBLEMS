#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int res = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x = int(a[i][j] - '0');

            if(i == 0 || j == 0) {
                dp[i][j] = x;
                res = max(res, dp[i][j]);
                continue;
            }

            if(!x) continue;
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

            res = max(res, dp[i][j]);
        }
    }
    cout<<res * res;
    return 0;
}