#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 45;
int w[maxn], v[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>w[i]>>v[i];

    vector<int> dp(m + 1, 0);

    dp[0] = 0;

    for(int i = 1; i<=n;i++)
        for(int j = m; j >= w[i];j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    
    cout<<dp[m];
    return 0;
}