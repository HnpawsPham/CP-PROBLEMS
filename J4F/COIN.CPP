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

const int MOD = 1e9 + 7;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, p;
    cin>>n>>p;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll dp[n + 1][2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        if(a[i] % 2){
            dp[i][1] = dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
        }
        else{
            dp[i][1] = dp[i - 1][1] * 2 % MOD;
            dp[i][0] = dp[i - 1][0] * 2 % MOD;
        }
    }
    cout<<dp[n][p];
    return 0;
}
