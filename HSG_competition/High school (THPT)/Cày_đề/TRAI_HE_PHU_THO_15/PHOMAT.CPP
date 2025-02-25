#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, l;

int main(){
    freopen("PHOMAT.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l;
    int t[n + 1], w[n + 1];
    for(int i = 1; i <= n; i++) cin>>t[i]>>w[i];

    int dp[n + 1][l + 1] = {};

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=l; j++){
            dp[i][j] = dp[i - 1][j];
            if(j >= t[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - t[i]] + w[i]);
        }
    }
    cout<<dp[n][l];

    return 0;
}