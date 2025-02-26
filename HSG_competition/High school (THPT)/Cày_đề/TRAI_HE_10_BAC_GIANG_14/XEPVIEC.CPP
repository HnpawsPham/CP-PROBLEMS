#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m;

int main(){
    freopen("XEPVIEC.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <=m ;j++) cin>>a[i][j];

    ll dp[n + 1][m + 1] = {};
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= m; j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        }
    }
    cout<<dp[n][m];

    return 0;
}