#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 220220061

int t, n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>k;
        ll dp[n + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++)
                dp[i][0] = (dp[i][0] + dp[i - 1][j]) % MOD;
            
            for(int j = 0; j < k; j++)
                dp[i][j + 1] = dp[i - 1][j]; 
        }

        ll res = 0;
        for(int i = 0; i <= k; i++)
            res = (res + dp[n][i]) % MOD;
        cout<<res<<el;
    }

    return 0;
}