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

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vector<vi>> dp(n + 1, vector<vi>(m + 1, vi(k, 0)));
    dp[1][1][a[0][0] % k] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int r = 0; r < k; r++){
                int z = (r + a[i - 1][j - 1]) % k;
                dp[i][j][z] = (dp[i][j][z] + dp[i][j - 1][r] + dp[i - 1][j][r]) % MOD;
            }
    cout<<dp[n][m][0];
    return 0;
}

// 3 3 3
// 5 2 4
// 3 0 5
// 0 7 2