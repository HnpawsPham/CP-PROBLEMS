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
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;

    int dp[n + 1][k + 1];
    const int MOD = 1e9 + 7;

    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++)
        dp[i][1] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            for(int x = 1; x * x <= i; x++){
                if(i % x) continue;
                dp[i][j] = (dp[i][j] + dp[x][j - 1]) % MOD;
                if(x != i / x)
                    dp[i][j] = (dp[i][j] + dp[i / x][j - 1]) % MOD;
            }
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        res = (res + dp[i][k]) % MOD;
    cout<<res;
    return 0;
}