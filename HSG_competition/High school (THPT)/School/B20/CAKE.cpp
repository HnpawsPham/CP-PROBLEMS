#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<ll, int>

int n, m, k;
const int maxn = 2 * (int)1e5 + 5;
ll a[maxn];

int main(){
    freopen(".\\txt\\CAKE.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m>>k;
    for(int i = 1;i<=n;i++) cin>>a[i];
    ll dp[201][n + 1];
    
    for(int i = 0; i <=k;i++)
        for(int j = 0;j<=n; j++) dp[i][j] = 0;

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[j] * i);
        }

        for(int x = 1; x < n; x++){
            dp[i][x + 1] = max(dp[i][x], dp[i][x + 1]);
        }
    }
    
    ll res = 0;
    for(int i = 1; i <=n;i++){
        res = max(res, dp[k][i]);
    }
    cout<<res<<el;
    
    return 0;
}