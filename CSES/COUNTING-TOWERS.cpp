#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int t, n;
const ll MOD = 1e9 + 7;
const int maxn = 1e6 + 1;
ll dp[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    dp[1] = 2;
    dp[2] = 8;

    for(int i = 3; i < maxn; i++){
        dp[i] = ((MOD - 7) * dp[i - 2] % MOD + 6 * dp[i - 1]) % MOD;
    }

    while(t--){
        cin>>n;
        cout<<dp[n]<<el;
    }

    return 0;
}