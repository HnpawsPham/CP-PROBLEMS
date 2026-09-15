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
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k;
    cin>>s>>k;
    int n = s.length();

    bool ispalin[n][n];
    memset(ispalin, 0, sizeof ispalin);

    for(int i = 0; i < n; i++)
        ispalin[i][i] = 1;

    for(int len = 2; len <= n; len++)
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            if(len == 2) ispalin[i][j] = (s[i] == s[j]);
            else ispalin[i][j] = ((s[i] == s[j]) && ispalin[i + 1][j - 1]);
        }

    int dp[n + 1];
    memset(dp, 0, sizeof dp);

    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1];
        for(int j = i - k; j >= 0; j--)
            if(ispalin[j][i - 1])
                dp[i] = max(dp[i], dp[j] + 1);
    }
    cout<<dp[n];
    return 0;
}

// abaccdbbd 3