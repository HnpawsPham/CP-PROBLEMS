#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll dp[n + 1];
    dp[1] = a[1];
    ll res = LLONG_MAX;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i - 1; j++){
            dp[i] = max(a[i], dp[j]);
            res = min(res, dp[i]);
        }
    }
    cout<<res;
    return 0;
}