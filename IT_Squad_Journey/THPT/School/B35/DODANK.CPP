#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

int n, k;
const int MOD = 1e9 + 7;

int main(){
    freopen("DODANK.INP", "r", stdin);
    freopen("DODANK.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<ll> dp(n + 1, 0), cnt(n + 1, 1);
    vector<ll> pdp(n + 1, 0), pcnt(n + 1, 0);
    
    for(int i = 1; i <= n; i++){
        dp[i] = a[i];
        cnt[i] = 1;

        if(i - k >= 0){
            dp[i] = ((dp[i] + pdp[i - k]) % MOD + 1LL * pcnt[i - k] * a[i] % MOD) % MOD;
            cnt[i] = (cnt[i] + pcnt[i - k]) % MOD;
        }

        pdp[i] = (pdp[i - 1] + dp[i]) % MOD;
        pcnt[i] = (pcnt[i - 1] + cnt[i]) % MOD;
    }

    ll sum = 0;
    for(const int& x : dp) sum = (sum + x) % MOD;
    cout<<sum;

    // vector<ll> dp(n + 1, 0), cnt(n + 1, 1);
    // ll cur, d;
    
    // for(int i = 0; i < n; i++){
    //     cur = a[i];
    //     d = 1;

    //     if(i - k >= 0){
    //         cur = ((cur + dp[i - k + 1]) % MOD + 1LL * cnt[i - k + 1] * a[i] % MOD) % MOD;
    //         d = (d + cnt[i - k + 1]) % MOD;
    //     }

    //     dp[i + 1] = (dp[i] + cur) % MOD;
    //     cnt[i + 1] = (cnt[i] + d) % MOD;
    // }

    // cout<<dp[n];
    return 0;
}

// 4 2
// 1 3 3 4

// 3 1
// 1 2 3