#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int dp[n][m];
    dp[0][0] = a[0][0];

    for(int i = 1; i < n; i++) dp[i][0] = dp[i - 1][0] + a[i][0];
    for(int j = 1; j < m; j++) dp[0][j] = dp[0][j - 1] + a[0][j];

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];

    cout<<dp[n - 1][m - 1];
    return 0;
}