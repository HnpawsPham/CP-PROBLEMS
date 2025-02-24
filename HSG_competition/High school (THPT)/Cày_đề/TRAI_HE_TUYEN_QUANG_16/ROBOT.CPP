#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define MOD 1000000000

int n, m;

int main(){
    freopen("ROBOT.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) dp[i][1] = 1;

    for(int j = 2; j <= m; j++){
        for(int i = 1; i <= n; i++){
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            if(i < n) dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % MOD;
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++) sum = (sum + dp[i][m]) % MOD;
    cout<<sum;
    return 0;
}