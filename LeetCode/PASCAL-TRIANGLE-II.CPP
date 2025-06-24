#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int dp[n + 1][n + 1] = {0};
    vector<int> res;

    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 0; i <= n; i++)
        dp[i][i] = 1;

    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= i; j++)
    //         cout<<dp[i][j]<<" ";
    //         cout<<el;
    // }
    for(int j = 0; j <= n; j++)
        res.push_back(dp[n][j]);

    for(int x : res) cout<<x<<" ";
    return 0;
}