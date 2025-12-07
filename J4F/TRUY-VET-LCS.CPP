#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
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

    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int j = 1; j <= m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i][j - 1];
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    string res = "";
    while(n && m){
        if(s[n - 1] == t[m - 1]){
            res.push_back(s[n - 1]);
            n--, m--;
        }
        else if(dp[n - 1][m] > dp[n][m - 1]) n--;
        else m--;
    }
    reverse(res.begin(), res.end());
    cout<<res;
    return 0;
}