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

const int MOD = 1e9 + 7;

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
    int dp[n][k + 1], p[k + 1];
    memset(dp, 0, sizeof dp);
    memset(p, 0, sizeof p);

    dp[0][0] = 1;
    p[0] = 1;
    for(int i = 1; i < n; i++)
        for(int j = k; j >= 0; j--){
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if(j > 0)
                dp[i][j] = (dp[i][j] + p[j - 1]) % MOD;
            p[j] = (p[j] + dp[i][j]) % MOD;
        }
    cout<<dp[n - 1][k];
    return 0;
}