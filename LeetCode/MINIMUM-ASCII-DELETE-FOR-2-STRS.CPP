#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int calc(const string& s){
    int sum = 0;
    for(const char& x : s)
        sum += x;
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();

    vector<vi> dp(n + 1, vi(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + int(s[i - 1]);
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    
    cout<<calc(s) + calc(t) - 2 * dp[n][m];
    return 0;
}