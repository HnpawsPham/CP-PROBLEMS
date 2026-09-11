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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    const int oo = 1e7 + 5;
    int dp[n + 1][k + 1][2];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j][0] = dp[i][j][1] = -oo;
            
    dp[0][0][1] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++){
            if(j > 0)
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] - a[i - 1]);

            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] + a[i - 1]);

            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1]);
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
        }

    int res = 0;
    for(int i = 0; i <= k; i++)
        res = max(res, max(dp[n][i][1], dp[n][i][0]));
    cout<<res;
    return 0;
}

// 3 2
// 2 4 1

// 6 2
// 3 2 6 5 0 3