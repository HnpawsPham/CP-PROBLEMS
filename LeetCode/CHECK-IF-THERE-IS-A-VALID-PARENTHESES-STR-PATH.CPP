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
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    if(a[0][0] != '(' || a[n - 1][m - 1] != ')') 
        return cout<<0, 0;

    bool dp[n + 1][m + 1][105];
    memset(dp, 0, sizeof dp);

    dp[1][1][1] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int d = a[i - 1][j - 1] == '(' ? 1 : -1;

            for(int k = 0; k <= 100; k++){
                int prev = k - d;
                if(prev < 0 || prev > 100) continue;

                dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][prev] || dp[i][j - 1][prev]; 
            }
        }
    cout<<dp[n][m][0];
    return 0;
}

// 4 3
// (((
// )()
// (()
// (()