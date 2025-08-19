#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int oo = 1e7 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    int k;
    cin>>s>>t>>k;
    int n = s.length(), m = t.length();

    vector<vi> dp(n + 1, vi(m + 1, oo));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[i][0] = i * k;
    for(int i = 1; i <= m; i++) dp[0][i] = i * k;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
                dp[i][j] = min({
                    dp[i - 1][j - 1] + abs(s[i - 1] - t[j - 1]), 
                    dp[i][j - 1] + k, 
                    dp[i - 1][j] + k
                });
        }
    cout<<dp[n][m];
    return 0;
}