#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int MOD = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, delay, forget;
    cin>>n>>delay>>forget;

    vector<ll> dp(n + 1, 0);
    dp[1] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j < i; j++){
            int d = i - j;
            if(d >= delay && d < forget)
                dp[i] = (dp[i] + dp[j]) % MOD;
        }
    
    ll res = 0;
    for(int i = n - forget + 1; i <= n; i++)
        res = (res + dp[i]) % MOD;
    cout<<res;
    return 0;
}

// 6 2 4

// 4 1 3