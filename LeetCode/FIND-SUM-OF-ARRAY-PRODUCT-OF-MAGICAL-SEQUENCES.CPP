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

int n, m, k;
const int MOD = 1e9 + 7;
const int maxm = 35;
ll fact[maxm], invfact[maxm];

ll ppow(ll a, ll b) {
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
};

void calc_fact(){
    fact[0] = invfact[1] = 1;
    for (int i = 1; i < maxm; i++) 
        fact[i] = fact[i - 1] * i % MOD;
    
    invfact[maxm - 1] = ppow(fact[maxm - 1], MOD - 2);
    for (int i = maxm - 1; i >= 1; i--) 
        invfact[i - 1] = invfact[i] * i % MOD;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    calc_fact();

    vector mat(n, vll(m + 1, 1));
    for (int i = 0; i < n; i++) 
        for (int j = 1; j <= m; j++) 
            mat[i][j] = mat[i][j - 1] * a[i] % MOD;

    vector dp(n, vector(m + 1, vector(m * 2 + 1, vll(k + 1, 0))));
    for (int j = 0; j <= m; j++) 
        dp[0][j][j][0] = mat[0][j] * invfact[j] % MOD;
    
    for (int i = 0; i + 1 < n; i++) 
        for (int j = 0; j <= m; j++) 
            for (int x = 0; x <= m * 2; x++) 
                for (int y = 0; y <= k; y++) {
                    int y2 = x % 2 + y;
                    if (y2 > k) break;
                    
                    for (int r = 0; r + j <= m; r++) {
                        int x2 = x / 2 + r;
                        dp[i + 1][j + r][x2][y2] += dp[i][j][x][y] * mat[i + 1][r] % MOD * invfact[r] % MOD;
                        dp[i + 1][j + r][x2][y2] %= MOD;
                    }
                }

    ll res = 0;
    for (int i = 0; i <= m * 2; i++) 
        for (int j = 0; j <= k; j++) 
            if (__builtin_popcount(i) + j == k) 
                res = (res + dp[n - 1][m][i][j] * fact[m] % MOD) % MOD;
    cout<<res;
    return 0;
}

// 1 1 1
// 28

// 5 2 2
// 5 4 3 2 1