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
const int sz = 105;

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

matrix operator * (const matrix& a, const matrix& b){
    matrix res;
    for(int i = 0; i < sz; i++)
        for(int k = 0; k < sz; k++){
            if(!a.val[i][k]) continue;

            for(int j= 0; j < sz; j++)
                res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j] % MOD) % MOD;
        }
    return res;
}

matrix powmat(const matrix& a, int b){
    if(b == 0){
        matrix x;
        return x.unit();
    }

    matrix half = powmat(a, b/ 2);
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

    int n, m, k;
    cin>>n>>m>>k;

    matrix dp;
    while(m--){
        int u, v;
        cin>>u>>v;
        dp.val[u][v] = 1;
    }
    dp = powmat(dp, k);

    ll res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            res = (res + dp.val[i][j]) % MOD;
    cout<<res;
    return 0;
}