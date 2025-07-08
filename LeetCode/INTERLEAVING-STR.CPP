#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s, s1, s2;
const int maxn = 101;
bool dp[maxn][maxn] = {0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    int len = s.length();

    if(n + m > len || len > n + m) return cout<<0, 0;

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s[i - 1]);

    for(int j = 1; j <= m; j++)
        dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s[j - 1]);

    for(int i = 1; i <= n; i++)  
        for(int j = 1; j <= m; j++){
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s[i + j - 1]) 
                    || (dp[i][j - 1] && s2[j - 1] == s[i + j - 1]);
        }

    cout<<dp[n][m];
    return 0;
}
// aadbbcbcac
// aabcc
// dbbca