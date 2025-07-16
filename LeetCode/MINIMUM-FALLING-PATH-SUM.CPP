#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n;
const int oo = 1e5 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    vector<vector<int>> dp(n, vector<int>(n, oo));

    for(int i = 0; i < n; i++) dp[0][i] = a[0][i];

    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++){
            if(j < n - 1) 
                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
            if(j > 0) 
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);

            dp[i][j] = min(dp[i][j], dp[i - 1][j]) + a[i][j];
        }
    
    int res = oo;
    for(int i = 0; i < n; i++)
        res = min(res, dp[n - 1][i]);
    cout<<res;
    return 0;
}