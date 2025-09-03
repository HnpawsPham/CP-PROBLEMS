#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("WORK.INP", "r", stdin);
    freopen("WORK.OUT", "w", stdout);

    int n;
    cin>>n;
    int t[n + 1], p[n + 1];
    for(int i = 1; i <= n; i++) cin>>t[i];
    for(int i = 2; i <= n; i++) cin>>p[i];

    int dp[n + 1] = {0};
    dp[1] = t[1];

    for(int i = 2; i <= n; i++)
        dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + p[i]);
    
    cout<<dp[n];
    return 0;
}