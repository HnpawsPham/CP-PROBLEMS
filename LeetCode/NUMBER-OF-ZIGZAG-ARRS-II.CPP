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

const int maxn = 155;
const int MOD = 1e9 + 7;

struct matrix{
    ll val[maxn][maxn];

    matrix(){
        memset(val, 0, sizeof val);
    }

    matrix& unit(){
        for(int i = 0; i < maxn; i++)
            val[i][i] = 1;
        return *this;
    }
};

matrix operator * (const matrix& a, const matrix& b){
    matrix res;

    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            for(int k = 0; k < maxn; k++)
                res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j] % MOD) % MOD;
    return res;
}

matrix operator * (const matrix& a, const matrix& b) {
    matrix res;
    for(int i = 0; i < maxn; i++) {
        for(int k = 0; k < maxn; k++) {
            if(a.val[i][k] == 0) continue;
            for(int j = 0; j < maxn; j++) 
                res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j]) % MOD;
        }
    }
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, l, r;
    cin>>n>>l>>r;

    int sz = r - l + 1;

    matrix dp, t;
    for(int i = 0; i < 2 * sz; i++)
        dp.val[0][i] = 1;
    
    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < i; j++) 
            t.val[i][j + sz] = 1;
        
        for(int j = i + 1; j < sz; j++) 
            t.val[i + sz][j] = 1;
    }
    
    t = powmat(t, n - 1);
    dp = dp * t;

    ll res = 0;
    for(int i = 0; i < 2 * sz; i++) 
        res = (res + dp.val[0][i]) % MOD;
    cout<<res;
    return 0;
}