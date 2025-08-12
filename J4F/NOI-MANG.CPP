#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const ll oo = 1e10;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll w[n + 1];
    for(int i = 1; i < n; i++) cin>>w[i];
    w[n] = oo;

    vector<ll> dp(n + 1, oo);
    dp[1] = dp[2] = w[1];

    for(int i = 3; i <= n; i++)
        dp[i] = min(dp[i - 2] + w[i - 1], dp[i - 1] + w[i]);

    cout<<dp[n];
    return 0;
}