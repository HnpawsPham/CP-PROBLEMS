#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const ll oo = 1e11 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<ll> dp(n + 1, oo),
                mp(k, oo);
    ll p = 0;
    mp[0] = dp[0] = 0;

    for(int i = 1; i <= n; i++){
        p += a[i - 1];
        dp[i] = dp[i - 1] + a[i - 1];
        int mod = p % k;
        
        mp[mod] = min(mp[mod], dp[i]);
        dp[i] = min(dp[i], mp[mod]);
    }
    cout<<dp[n];
    return 0;
}