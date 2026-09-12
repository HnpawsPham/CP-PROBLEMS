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
#define taskname "GAME"

int n, m, k;
const int MOD = 1e9 + 7;

namespace sub1{
    int dp[205][5005];

    void sol(){
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;

        for(int x = 0; x <= k; x++){
            for(int j = 1; j <= m; j++)
                for(int i = x; i <= n; i++)
                    dp[i][j] = (dp[i][j] + dp[i - x][j - 1]) % MOD;
        }
        cout<<dp[n][m];
    }
}

namespace sub3{
    const int maxn = 5005;
    int dp[maxn][maxn], p[maxn];

    void sol(){
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;

        for(int x = 0; x <= k; x++){
            for(int j = 1; j <= m; j++)
                for(int i = x; i <= n; i++)
                    dp[i][j] = (dp[i][j] + dp[i - x][j - 1]) % MOD;
        }
        cout<<dp[n][m];
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    if(n <= 205) sub1::sol();
    return 0;
}