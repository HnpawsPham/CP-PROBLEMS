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

    int n, m, k;
    cin>>n>>m>>k;
    int a[n][m];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin>>a[i][j];

    const int oo = 2e7 + 5;
    vector<vector<vi>> dp(n + 1, vector<vi>(m + 1, vi(k + 1, -oo)));
    dp[0][0][0] = dp[1][0][0] = dp[0][1][0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            for(int s = k; s >= 0; s--){
                int d = a[i - 1][j - 1] != 0;
                if(s >= d)
                dp[i][j][s] = max(dp[i][j][s], 
                              max(dp[i][j - 1][s - d], dp[i - 1][j][s - d]) + a[i - 1][j - 1]);
            }
        }
    
    int res = *max_element(dp[n][m].begin(), dp[n][m].end());
    cout<<max(-1, res);
    return 0;
}

// 2 2 1
// 0 1
// 2 0