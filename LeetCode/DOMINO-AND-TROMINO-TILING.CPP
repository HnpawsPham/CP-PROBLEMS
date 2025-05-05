#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define MOD 1000000007

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> dp(n + 1);
    dp[0] = dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
        dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD;
        
    cout<<dp[n];

    return 0;
}