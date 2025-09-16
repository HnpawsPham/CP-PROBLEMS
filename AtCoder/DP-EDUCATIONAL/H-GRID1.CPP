#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define vll vector<ll>
#define fi first
#define se second

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    char a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];
    
    vector<vll> dp(n, vll(m, 0));
    if(a[0][0] != '.') return cout<<0, 0;
    dp[0][0] = 1;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] != '.') continue;

            if(i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++) cout<<dp[i][j]<<" ";
    //     cout<<el;
    // }
    cout<<dp[n - 1][m - 1];
    return 0;
}