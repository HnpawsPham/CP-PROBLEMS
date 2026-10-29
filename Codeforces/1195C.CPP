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
    int a[2][n];
    for(int i = 0; i < n; i++) cin>>a[0][i];
    for(int i = 0; i < n; i++) cin>>a[1][i];

    ll dp[2][n][2];
    memset(dp, 0, sizeof dp);
    dp[0][0][1] = a[0][0];
    dp[1][0][1] = a[1][0];

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 2; j++){
            dp[0][i][0] = max(dp[0][i][0], max(dp[0][i - 1][j], dp[1][i - 1][j]));
            dp[1][i][0] = max(dp[1][i][0], max(dp[0][i - 1][j], dp[1][i - 1][j]));
        }
        dp[0][i][1] = max(dp[1][i - 1][1], max(dp[1][i - 1][0], dp[0][i - 1][0])) + a[0][i];
        dp[1][i][1] = max(dp[0][i - 1][1], max(dp[1][i - 1][0], dp[0][i - 1][0])) + a[1][i];
    }
    cout<<max(max(dp[0][n - 1][1], dp[1][n - 1][1]), max(dp[0][n - 1][0], dp[1][n - 1][0]));
    return 0;
}