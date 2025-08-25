#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, MOD;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>MOD;

    ll dp[n + 1][n + 1] = {0};
    dp[1][1] = 1;
    ll res = 0;

    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++){
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * j % MOD * 2 % MOD) % MOD;
            dp[i][j] = (dp[i][j] + (dp[i - 2][j - 1] * j % MOD)) % MOD;

            if(i == n) res = (res + dp[i][j]) % MOD;
        }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++) cout<<dp[i][j]<<" ";
    //     cout<<el;
    // }
    cout<<res;
    return 0;
}