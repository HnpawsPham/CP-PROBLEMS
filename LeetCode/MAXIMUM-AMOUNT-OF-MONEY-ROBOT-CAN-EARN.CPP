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

    int n, m;
    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    const int oo = 1e8 + 5;
    vector<vector<vi>> dp(n, vector<vi>(m, vi(3, -oo)));
    dp[0][0][0] = a[0][0];
    dp[0][0][1] = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < 3; k++){
                if(i > 0){
                    dp[i][j][k] = max(dp[i - 1][j][k] + a[i][j], dp[i][j][k]);
                    if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                }
                if(j > 0){
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + a[i][j]);
                    if(k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                }
            }
        
    cout<<*max_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
    return 0;
}

// 3 3
// 0 1 -1
// 1 -2 3
// 2 -3 4
