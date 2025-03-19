#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll dp[n + 5];
    dp[0] = dp[1] = 1;

    for(int i = 2; i<=n;i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout<<dp[n]<<el;
    
    return 0;
}