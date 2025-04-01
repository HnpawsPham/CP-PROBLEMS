#include <iostream>
using namespace std;

string s1, s2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s1>>s2;
    int n = s1.length(), m = s2.length();

    int dp[n + 1][m + 1];
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++) dp[i][0] = 0;
    for(int j = 1; j <= m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }

    cout<<dp[n][m];
    return 0;
}