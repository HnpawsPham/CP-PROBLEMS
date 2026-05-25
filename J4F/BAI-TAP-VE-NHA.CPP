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
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    const ll oo = 1e14 + 5;
    vector<vll> dp(n, vll(3, -oo));
    dp[0][0] = a[0];
    dp[0][1] = dp[0][2] = a[0] * x;
    ll res = max(dp[0][0], max(dp[0][1], dp[0][2]));
   
    for(int i = 1; i < n; i++){
        dp[i][0] = max(a[i], dp[i - 1][0] + a[i]);
        dp[i][1] = max(dp[i - 1][0] + a[i] * x, max(dp[i - 1][1] + a[i] * x, a[i] * x));
        dp[i][2] = max(dp[i - 1][1] + a[i], max(dp[i - 1][2] + a[i], a[i]));
        res = max(max(res, dp[i][0]), max(dp[i][1], dp[i][2]));
    }
    cout<<res;
    return 0;
}