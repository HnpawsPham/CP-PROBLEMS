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

    int dp[n + 1][n + 2];
    const int oo = 3e6 + 6;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n + 1; j++)
            dp[i][j] = oo;
        
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= i; j++){
            if(a[i - 1] > 100){ 
                if(j > 0) 
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i - 1]);
            }
            else dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i - 1]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
        }
    
    int res = oo;
    for(int i = 0; i <= n; i++)
        res = min(res, dp[n][i]);
    cout<<res;
    return 0;
}