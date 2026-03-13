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

    int cnt0, cnt1, lim;
    cin>>cnt0>>cnt1>>lim;

    const int MOD = 1e9 + 7;
    int dp[cnt0 + 1][cnt1 + 1][2];
    
    for(int i = 0; i <= min(cnt0, lim); i++)
        dp[i][0][0] = 1;

    for(int i = 0; i <= min(cnt1, lim); i++)
        dp[0][i][1] = 1;

    for(int i = 1; i <= cnt0; i++)
        for(int j = 1; j <= cnt1; j++){
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
            dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;

            if(i > lim) dp[i][j][0] = (dp[i][j][0] - dp[i - lim - 1][j][1] + MOD) % MOD;
            if(j > lim) dp[i][j][1] = (dp[i][j][1] - dp[i][j - lim - 1][0] + MOD) % MOD;
        }
    cout<<(dp[cnt0][cnt1][0] + dp[cnt0][cnt1][1]) % MOD;
    return 0;
}