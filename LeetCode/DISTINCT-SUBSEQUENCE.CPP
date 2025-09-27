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

    string s, t;
    cin>>s>>t;
    int n = s.length(), m = t.length();

    vector<vi> dp(n + 1, vi(m + 1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = 1;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        dp[i][j] = dp[i - 1][j];
        if(s[i - 1] == t[j - 1])
            dp[i][j] += dp[i - 1][j - 1]; 
    }
    cout<<dp[n][m];
    return 0;
}