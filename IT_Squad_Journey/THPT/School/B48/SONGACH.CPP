#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define taskname "SONGACH"

const int MOD = 998244353;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;

    ll dp[n + 1][k + 1];
    memset(dp, 0, sizeof dp);
    dp[1][0] = m;

    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i - 1][0];
        for(int j = 1; j <= k; j++)
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * 1LL * (m - 1) % MOD) % MOD;
    }
    cout<<dp[n][k];
    return 0;
}