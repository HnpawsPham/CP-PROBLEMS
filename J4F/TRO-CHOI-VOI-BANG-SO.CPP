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

    int dp[n + 1][2];
    for(int i = 1; i<= n; i++)
        dp[i][0] = dp[i][1] = -1e11 - 5;

    dp[0][0] = dp[0][1] = 0;
    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][1] + a[i - 1], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] - a[i - 1], dp[i - 1][1]);
    }
    
    ll res = 0;
    for(int i = 1; i <= n; i++)
        res = max(res, max(dp[i][1], dp[i][0]));
    cout<<res;
    return 0;
}