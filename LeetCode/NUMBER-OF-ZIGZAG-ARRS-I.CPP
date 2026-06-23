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

int dp[2005][2005][2];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l, r;
    cin>>n>>l>>r;

    const int MOD = 1e9 + 7;
    memset(dp, 0, sizeof dp);

    for(int i = l; i <= r; i++)
        dp[1][i][0] = dp[1][i][1] = 1;

    for(int i = 2; i <= n; i++){
        vi p(r + 1, 0), s(r + 2, 0);

        for(int j = l; j <= r; j++)
            p[j] = (p[j - 1] + dp[i - 1][j][1]) % MOD;

        for(int j = r; j >= l; j--)
            s[j] = (s[j + 1] + dp[i - 1][j][0]) % MOD;

        for(int j = l; j <= r; j++){
            dp[i][j][0] = (dp[i][j][0] + p[j - 1]) % MOD;
            dp[i][j][1] = (dp[i][j][1] + s[j + 1]) % MOD;
        }
    }
    
    int res = 0;
    for(int i = l; i <= r; i++){
        res = (res + dp[n][i][0]) % MOD;
        res = (res + dp[n][i][1]) % MOD;
    }
    cout<<res;
    return 0;
}