#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vi p(n), s(n);
    p[0] = a[0]; s[n - 1] = a[n - 1];
    for(int i = 0; i < n - 1; i++)
        p[i + 1] = max(p[i], a[i + 1]);

    for(int i = n - 1; i > 0; i--)
        s[i - 1] = min(s[i], a[i - 1]);

    // for(int x : p) cout<<x<<" ";
    // cout<<el;
    // for(int x : s) cout<<x<<" ";

    vi dp(n);
    dp[n - 1] = p[n - 1];
    for(int i = n - 2; i >= 0; i--){
        dp[i] = p[i];
        if(s[i + 1] < dp[i]) dp[i] = max(dp[i], dp[i + 1]);
    }
    return 0;
}

// 3
// 2 1 3