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
const int oo = 1e12 + 5;

void sol(){
    int n, d;
    cin>>n>>d;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
  
    ll dp[n + 1][n + 1];
    
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -oo;

    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++){
            if(j > 0){
                dp[i][j] = max(0, a[i - 1] + d);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i - 1] + d);
            }
            else dp[i][j] = max(0, a[i - 1]);

            dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i - 1]);
        }
    
    for(int i = 0; i <= n; i++){
        ll res = 0;
        for(int j = 1; j <= n; j++)
            res = max(res, dp[j][i]);
        cout<<res<<" ";
    }
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
        sol();
        cout<<el;
    }
    return 0;
}