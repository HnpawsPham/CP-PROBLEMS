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

ll n;
const ll MOD = 1e9 + 7;
const int sz = 2;

struct matrix{
    ll val[sz][sz];

    matrix(){
        memset(val, 0, sizeof val);
    }

    matrix unit(){
        for(int i = 0; i < sz; i++)
            val[i][i] = 1;
        return *this;
    }
};

matrix operator * (const matrix& a, const matrix & b){
    matrix res;
    for(int i = 0; i < sz; i++)
        for(int k = 0; k < sz; k++){
            if(!a.val[i][k]) continue;

            for(int j = 0; j < sz; j++)
                res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j] % MOD) % MOD;
        }
    return res;
}

matrix powmat(const matrix& a, ll b){
    if(b == 0){
        matrix x;
        return x.unit();
    }

    matrix half = powmat(a, b / 2);
    if(b & 1) return half * half * a;
    return half * half;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    matrix t;
    t.val[0][0] = 19;
    t.val[0][1] = 6;
    t.val[1][0] = 7;
    t.val[1][1] = 20;

    matrix dp;
    dp.val[0][0] = 1;
    dp.val[1][0] = 0;

    t = powmat(t, n);
    dp = dp * t;
    cout<<dp.val[0][0];

    // ll dp[n + 1][2] = {0};
    // dp[0][0] = 1;
    // dp[0][1] = 0;

    // for(int i = 1; i <= n; i++){
    //     dp[i][0] = (dp[i - 1][0] * 19 % MOD + dp[i - 1][1] * 6 % MOD) % MOD;
    //     dp[i][1] = (dp[i - 1][1] * 20 % MOD + dp[i - 1][0] * 7 % MOD) % MOD;
    // }
    // cout<<dp[n][0];
    return 0;
}