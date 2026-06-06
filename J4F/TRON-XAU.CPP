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

int tc = 1;
int n, m;

ll sol(){
    cin>>n>>m;
    int w[n + 1][m + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin>>w[i][j];

    ll dp[n + 1][m + 1][2];
    const ll oo = 1e16 + 5;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j][1] = dp[i][j][0] = oo;
    
    for(int i = 0; i <= n; i++)
        dp[i][0][0] = 0;

    for(int j = 0; j <= m; j++)
        dp[0][j][1] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + w[i][j]);
            dp[i][j][1] = min(dp[i][j - 1][0] + w[i][j], dp[i][j - 1][1]);
        }
    return min(dp[n][m][0], dp[n][m][1]);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}