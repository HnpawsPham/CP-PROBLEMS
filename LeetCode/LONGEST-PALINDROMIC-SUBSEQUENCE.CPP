#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;
vector<vector<int>> dp;

int sol(int i, int j){
    if(i == j) return 1;
    if(dp[i][j]) return dp[i][j];
    if(j < i) return 0;

    if(s[i - 1] == s[j - 1])
        return dp[i][j] = sol(i + 1, j - 1) + 2;

    else return dp[i][j] = max(sol(i + 1, j), sol(i, j - 1));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();

    // vector<vector<int>> dp(n, vector<int>(n, 0));
    // for(int i = 0; i < n; i++) dp[i][i] = 1;
    // int res = 0;

    // for(int i = n - 1; i >= 0; i--)
    //     for(int j = i; j < n; j++){
    //         if(s[i] == s[j] && i < n - 1 && j > 0)
    //             dp[i][j] = dp[i + 1][j - 1] + 2;

    //         else{
    //             if(i < n - 1) dp[i][j] = dp[i + 1][j];
    //             if(j > 0) dp[i][j] = max(dp[i][j - 1], dp[i][j]);
    //         }
    //         res = max(res, dp[i][j]);
    //     }

    dp.assign(n + 2, vector<int>(n + 2, 0));
    // for(int i = 1; i <= n; i++) dp[i][i] = 1;
    // int res = 0;

    // for(int i = n; i > 0; i--)
    //     for(int j = i + 1; j <= n; j++){
    //         if(s[i - 1] == s[j - 1])
    //             dp[i][j] = dp[i + 1][j - 1] + 2;

    //         else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
    //         res = max(res, dp[i][j]);
    //     }
    // cout<<res;
    cout<<sol(1, n);
    return 0;
}