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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll dp[n + 1][k], res[k];
    memset(res, 0, sizeof res);
    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++)
            dp[i][j * (a[i - 1] % k) % k] += dp[i - 1][j];       
            
        dp[i][a[i - 1] % k]++;

        for(int j = 0; j < k; j++)
            res[j] += dp[i][j];
    }
    
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 5 3
// 1 2 3 4 5