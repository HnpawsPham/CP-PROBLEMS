#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n";
#define MOD 1000000007

int n;

ll customPow(int a, int b){
    if(b == 0) return 1;
    if(b % 2 == 0) return customPow(a, b / 2) * customPow(a, b / 2);
    else return customPow(a, b / 2) * customPow(a, b / 2) * a;
}

int main(){
    freopen(".\\txt\\TAM-PHAN.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll dp[n + 1][3];
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;

    for(int i = 2; i <=n; i++){
        ll t = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][0] = dp[i][2] = t;
        dp[i][1] = t - dp[i - 1][1];
    }
    cout<<dp[n][0] + dp[n][1] + dp[n][2]<<el;

    return 0;
}