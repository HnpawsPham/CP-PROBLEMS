#include <bits/stdc++.h>
using ll = long long;
#define el '\n'
using namespace std;

const ll oo = -1e18; 

void sol() {
    int n;
    cin >> n;

    vector<int> cnt(51, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x >= 0 && x <= 50) cnt[x]++;
    }

    vector<vector<ll>> dp(51, vector<ll>(n + 1, oo));

    for (int j = 0; j <= cnt[0]; ++j) 
        dp[0][j] = 0;
    

    for (int i = 1; i <= 50; ++i) {
        vector<ll> maxx(n + 1, oo);
        ll cur = oo;

        for (int k = n; k >= 0; --k) {
            if (dp[i - 1][k] != oo) {
                ll tmp = dp[i - 1][k] + (ll)k * i;
                if (cur == oo || tmp > cur) {
                    cur = tmp;
                }
            }
            maxx[k] = cur;
        }

        for (int j = 0; j <= n; ++j) {
            if (j > cnt[i])  continue; 
        
            if (maxx[j] != oo) 
                dp[i][j] = (ll)cnt[i] * i - (ll)2 * j * i + maxx[j];
            
        }
    }

    ll res = 0;
    for (int j = 0; j <= n; ++j) {
        if (dp[50][j] != oo) 
            res = max(res, dp[50][j] + (ll)j * 51);
    }

    cout<<res<<el;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}