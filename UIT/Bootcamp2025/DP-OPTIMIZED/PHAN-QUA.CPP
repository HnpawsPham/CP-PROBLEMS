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

    int n, k;
    cin>>n>>k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++) 
        p[i] = p[i - 1] + a[i];

    // vector<ll> dp(n + 1, -oo);
    // deque<int> dq;
    // dp[0] = 0;
    // ll res = -oo, sum = 0;

    // for(int i = 1; i <= n; i++){
  
    // }
    // cout<<max(res, (ll)*max_element(a + 1, a + n + 1));

    ll dp[n + 1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        
        for(int j = 1; j <= k && i - j >= 0; j++)
            dp[i] = max(dp[i], dp[max(0, i - j - 1)] + p[i] - p[i - j]);
    }
    cout<<*max_element(dp + 1, dp + n + 1);
    return 0;
}