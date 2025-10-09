#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define vll vector<ll>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    vector<ll> dp(n, 0);
    for(int x : b){
        ll tmp = dp[0];
        for(int i = 1; i < n; i++)
            tmp = max(tmp + 1LL * a[i - 1] * x, dp[i]);

        dp[n - 1] = tmp + 1LL * a[n - 1] * x;
        for(int i = n - 2; i >= 0; i--)
            dp[i] = dp[i + 1] - 1LL * a[i + 1] * x;
    }
    cout<<dp[n - 1];
    return 0;
}

// 4 4
// 1 5 2 4
// 5 1 4 2