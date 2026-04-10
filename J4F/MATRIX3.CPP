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

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    ll dp[n + 1][m + 1][3];
    const ll oo = 1e16 + 5;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++) 
            for(int k = 0; k < 3; k++) dp[i][j][k] = -oo;

    dp[1][1][0] = a[0][0];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(i == 1 && j == 1) continue;

            for(int k = 0; k < 3; k++){
                if(k == 0)
                    dp[i][j][k] = max(dp[i][j][k], max(dp[i][j - 1][0], 
                                  max(dp[i][j - 1][1], dp[i][j - 1][2])));

                else dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
       
                dp[i][j][k] += a[i - 1][j - 1];
            }
        }
    cout<<max(dp[n][m][0], max(dp[n][m][1], dp[n][m][2]));
    return 0;
}