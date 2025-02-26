#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    freopen("KHOBAU.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll l[n + 1], w[n + 1];
    for(int i = 1; i <= n; i++) cin>>l[i]>>w[i];

    ll max_l[n + 1][n + 1] = {}, 
    max_w[n + 1][n + 1] = {};

    for(int i = 1; i <= n; i++){
        max_l[i][i] = l[i];
        max_w[i][i] = w[i];
        for(int j = i + 1; j <= n; j++){
            max_l[i][j] = max(l[j], max_l[i][j - 1]);
            max_w[i][j] = max(w[j], max_w[i][j - 1]);
        }
    }

    ll dp[n + 1];
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i] = LLONG_MAX;
        for(int j = 1; j <= i; j++){
            dp[i] = min(dp[i], dp[j - 1] + 1LL * max_l[j][i] * max_w[j][i]);
        }
    }
    cout<<dp[n];
    return 0;
}