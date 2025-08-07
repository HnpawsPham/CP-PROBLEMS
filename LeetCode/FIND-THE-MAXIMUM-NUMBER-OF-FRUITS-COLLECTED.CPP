#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define fi first
#define se second
#define pii pair<int, int>

int n;
vector<vi> dp;

void getmax(int i, int j, int i1, int j1, int w){
    if(i1 < 0 || j1 < 0 || i1 == n || j1 == n) return;

    if(dp[i1][j1] + w > dp[i][j])
        dp[i][j] = dp[i1][j1] + w;

    return return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<vi> a(n, vi(n));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) cin>>a[i][j];

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i][i];
        a[i][i] = 0;
    }

    dp.assign(n, vi(n, 0));

    // child(0, n - 1)
    dp[0][n - 1] = a[0][n - 1];

    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++){
            getmax(i, j, i - 1, j, a[i][j]);
            getmax(i, j, i - 1, j - 1, a[i][j]);
            getmax(i, j, i - 1, j + 1, a[i][j]);
            // a[best.fi][best.se] = 0;
        }
    
    sum += dp[n - 1][n - 1];
    dp.assign(n, vi(n, 0));

    // child (n - 1, 0)
    dp[n - 1][0] = a[n - 1][0];

    for(int j = 1; j < n; i++)
        for(int i = 0; i < n; i++){
            getmax(i, j, i + 1, j - 1, a[i][j]);
            getmax(i, j, i - 1, j - 1, a[i][j]);
            getmax(i, j, i, j - 1, a[i][j]);
        }

    sum += dp[n - 1][n - 1];

    // cout<<dp[n - 1][n - 1]<<el;
    // for(auto v : dp){
    //     for(int x : v) cout<<x<<" ";
    //     cout<<el;
    // }

    // for(auto v : a){
    //     for(int x : v) cout<<x<<" ";
    //     cout<<el;
    // }
    cout<<sum;
    return 0;
}

// 4
// 1 2 3 4
// 5 6 8 7
// 9 10 11 12
// 13 14 15 16