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
#define taskname "CAU2"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string t;
    cin>>t;
    int n = t.length();

    bool dp[n + 1][n + 1];
    memset(dp, 0, sizeof dp);

    ll p[n + 1] = {0}, s[n + 2];
    memset(p, 0, sizeof p);
    memset(s, 0, sizeof s);

    for(int i = 1; i <= n; i++){
        dp[i][i] = 1;
        s[i]++; p[i]++;
    }

    for(int len = 2; len <= n; len++)
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            if(t[i - 1] != t[j - 1]) continue;

            if(len == 2) dp[i][j] = dp[i][j - 1];
            else dp[i][j] = dp[i + 1][j - 1];

            if(dp[i][j]){
                p[j]++;
                s[i]++;
            }
        }

    for(int i = 1; i <= n; i++)
        p[i] += p[i - 1];

    ll cnt = 0;
    for(int i = 1; i <= n; i++)
        cnt += p[i] * s[i + 1];
    cout<<cnt;
    return 0;
}