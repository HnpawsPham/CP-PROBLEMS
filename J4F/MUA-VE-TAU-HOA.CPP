#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const ll oo = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l[3], c[3];
    int n, s, t;
    cin>>l[0]>>l[1]>>l[2]>>c[0]>>c[1]>>c[2];
    cin>>n>>s>>t;

    if(s > t) swap(s, t);
    ll dis[n + 1] = {0};
    for(int i = 2; i <= n; i++) cin>>dis[i];

    ll res = 0;
    vector<ll> dp(t + 1, oo);
    dp[s] = 0;

    for(int i = s + 1; i <= t; i++)
        for(int j = 0; j < 3; j++){
            int pos = lower_bound(dis + s, dis + i, dis[i] - l[j]) - dis;
            dp[i] = min(dp[i], dp[pos] + c[j]);
        }
    cout<<dp[t];
    return 0;
}