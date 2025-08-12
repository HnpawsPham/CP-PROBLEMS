#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

const int MOD = 1e9 + 7;

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);

    if(b & 1) return half * half * a;
    return half * half;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin>>n>>x;

    vll dp(n + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        int w = ppow(i, x);
        if(w > n) break;

        for(int j = n; j >= w; j--)
            dp[j] = (dp[j] + dp[j - w]) % MOD;
    }
    cout<<dp[n];
    return 0;
}