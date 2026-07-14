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

const int MOD = 1e9 + 7;
int dp[205][205], tmp[205][205];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int m = 0;
    for(const int& x : a)
        m = max(m, x);

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for(const int& x : a){
        memset(tmp, 0, sizeof tmp);
        for(int i = m; i >= 0; i--)
            for(int j = m; j >= 0; j--){
                tmp[i][j] = (tmp[i][j] + dp[i][j]) % MOD;

                int s1 = __gcd(x, i), s2 = __gcd(x, j);
                tmp[s1][j] = (tmp[s1][j] + dp[i][j]) % MOD;
                tmp[i][s2] = (tmp[i][s2] + dp[i][j]) % MOD;
            }
        memcpy(dp, tmp, sizeof dp);
    }

    int res = 0;
    for(int i = 1; i <= m; i++)
        res = (res + dp[i][i]) % MOD;
    cout<<res;
    return 0;
}

// 4
// 1 2 3 4