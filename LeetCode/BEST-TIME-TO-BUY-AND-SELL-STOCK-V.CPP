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

const int oo = 1e9 + 5;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> dp(n + 1, vi(k + 1, 0));
    for(int t = 1; t <= k; t++){
        int best1 = -oo, best2 = -oo;

        for(int i = 1; i <= n; i++){
            dp[i][t] = dp[i - 1][t];
            dp[i][t] = max(dp[i][t], max(best1 - a[i - 1], best2 + a[i - 1]));

            best1 = max(best1, dp[i - 1][t - 1] + a[i - 1]);
            best2 = max(best2, dp[i - 1][t - 1] - a[i - 1]);
        }
    }
    cout<<dp[n][k];
    return 0;
}

// 5 2
// 1 7 9 8 2

// 9 3
// 12 16 19 19 8 1 19 13 9