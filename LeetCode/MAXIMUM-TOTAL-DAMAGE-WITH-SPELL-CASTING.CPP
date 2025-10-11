#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, ll>
#define fi first
#define se second

const ll oo = 1e15;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    map<int, ll> mp;
    for(int x : a) mp[x] += x;

    vector<pii> w(mp.begin(), mp.end());
    int m = w.size();

    vector<ll> dp(m, 0);
    dp[0] = w[0].se;

    for(int i = 1; i < m; i++){
        int target = w[i].fi - 3;

        int pos = upper_bound(w.begin(), w.begin() + i, make_pair(target, oo)) - w.begin() - 1;
        if(pos >= 0)
            dp[i] = max(dp[i - 1], w[i].se + dp[pos]);
        else dp[i] = max(dp[i - 1], w[i].se);
    }
    cout<<dp[m - 1];
    return 0;
}

// 4
// 1 1 3 4

// 4
// 7 1 6 6