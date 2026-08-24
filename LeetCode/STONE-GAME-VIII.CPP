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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int dp[n], p[n + 1];
    p[0] = 0;

    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];

    memset(dp, 0, sizeof dp);
    dp[n - 1] = p[n];

    for(int i = n - 2; i > 0; i--)
        dp[i] = max(dp[i + 1], p[i + 1] - dp[i + 1]);
    cout<<dp[1];
    return 0;
}

// 5
// -1 2 -3 4 -5