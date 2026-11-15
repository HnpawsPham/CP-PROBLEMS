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

    int n,m;
    cin>>n>>m;
    bool a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int dp[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j] = 1;

    int res = 1;
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++){
            if(a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i - 1][j] && a[i][j] == a[i][j - 1])
                dp[i][j] = max(dp[i][j], min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1);
            res = max(res, dp[i][j]);
        }
    cout<<res;
    return 0;
}