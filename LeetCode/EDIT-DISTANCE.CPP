#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

string s1, s2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s1>>s2;
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[0][0] = 0;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++){
            if(i != 0) dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
            if(j != 0) dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);

            if(i != 0 && j != 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
        }
    cout<<dp[n][m];
    return 0;
}