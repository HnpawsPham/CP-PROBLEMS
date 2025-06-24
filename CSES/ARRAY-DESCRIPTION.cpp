#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007

int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    if(a[1] == 0)
        for(int i = 1; i <= m; i++) dp[1][i] = 1;
    else dp[1][a[1]] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] != 0 && j != a[i]){
                dp[i][j] = 0;
                continue;
            }
            
            dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;

            if(j < m)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }
    }
    
    ll sum = 0;
    for(int i = 1; i <= m; i++)
        sum = (sum + dp[n][i]) % MOD;
    cout<<sum;
    return 0;
}