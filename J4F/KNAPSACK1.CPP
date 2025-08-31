#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin>>n>>w;
    pii a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i].fi>>a[i].se;

    vector<vector<ll>> dp(n + 1, vector<ll>(w + 1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = dp[i - 1][j];

            if(j >= a[i].fi)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].fi] + a[i].se);
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j <= w; j++) cout<<dp[i][j]<<" ";
    //     cout<<el;
    // }
    cout<<*max_element(dp[n].begin(), dp[n].end());
    return 0;
}