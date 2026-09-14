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
#define taskname "HACKATHON"

int n, m, k, sz;
const int maxn = 1e5 + 5;
const ll oo = 1e12 + 5;
int a[maxn], b[maxn], c[maxn];

namespace sub1{
    void sol(){
        vector<vector<vll>> dp(n + 2, vector<vll>(m + 2, vll(k + 2, oo)));
        dp[n][m][k] = 0;

        for(int i = n; i >= 0; i--)
            for(int j = m; j >= 0; j--)
                for(int z = k; z >= 0; z--){
                    int pos = i + j + z;

                    dp[i][j][z] = min(dp[i][j][z], min(min(
                    dp[i + 1][j][z] + a[pos],
                    dp[i][j + 1][z] + b[pos]),
                    dp[i][j][z + 1] + c[pos]));
                }
        cout<<dp[0][0][0];
    }
}

namespace sub2{
    void sol(){
        vector<vll> dp(n + 1, vll(m + 1, oo));
        dp[0][0] = 0;

        for(int pos = 0; pos < sz; pos++){
            vector<vll> tmp(n + 1, vll(m + 1, oo));

            for(int i = 0; i <= min(pos + 1, n); i++)
                for(int j = 0; j <= min(pos + 1 - i, m); j++){
                    int z = pos - i - j;

                    if(i > 0) tmp[i][j] = min(tmp[i][j], dp[i - 1][j] + a[pos]);
                    if(j > 0) tmp[i][j] = min(tmp[i][j], dp[i][j - 1] + b[pos]);
                    tmp[i][j] = min(tmp[i][j], dp[i][j] + c[pos]);
                }
            dp = tmp;
        }
        cout<<dp[n][m];
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin>>n>>m>>k;
    sz = n + m + k;
    for(int i = 0; i < sz; i++)
        cin>>a[i]>>b[i]>>c[i];

    if(sz <= 0) sub1::sol();
    else sub2::sol();
    return 0;
}