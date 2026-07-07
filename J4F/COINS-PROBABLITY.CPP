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

    int n;
    cin>>n;
    db a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    db dp[n + 1][n + 1] = {0};
    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++){
            dp[i][j] = dp[i - 1][j] * (1.0 - a[i]);
            if(j > 0) dp[i][j] += dp[i - 1][j - 1] * a[i];
        }

    db res = 0;
    for(int i = n / 2 + 1; i <= n; i++)
        res += dp[n][i];
    cout<<res;
    return 0;
}