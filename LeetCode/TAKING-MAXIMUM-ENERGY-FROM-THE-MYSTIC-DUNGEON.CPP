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

    int n, k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vi dp(n);
    int res = -1005;
    
    for(int i = 0; i < n; i++){
        dp[i] = a[i];
        if(i - k >= 0) dp[i] = max(dp[i], dp[i - k] + a[i]);
        if(i + k >= n) res = max(res, dp[i]);
    }
    cout<<res;
    return 0;
}

// 5 3
// 5 2 -10 -5 1

// 3 2
// -2 -3 -1