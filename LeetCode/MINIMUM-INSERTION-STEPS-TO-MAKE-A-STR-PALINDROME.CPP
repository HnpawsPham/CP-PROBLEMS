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
    cin>>s;

    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof dp);
    
    for(int i = 0; i < n; i++)
        dp[i][i] = 1;

    for(int len = 2; len <= n; len++)
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            if(s[i] == s[j]){
                if(len == 2) dp[i][j] = 2;
                else dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    cout<<n - dp[0][n - 1];
    return 0;
}