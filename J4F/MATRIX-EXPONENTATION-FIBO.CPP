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

const ll MOD = 1e9 + 7;

struct matrix{
    ll val[2][2];

    matrix(){
        memset(val, 0, sizeof val);
    }

    matrix& unit(){
        for(int i = 0; i < 2; i++)
            val[i][i] = 1;
        return *this;
    }
};

matrix operator * (const matrix& a, const matrix & b){
    matrix res;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                res.val[i][j] = (res.val[i][j] + a.val[i][k] * b.val[k][j] % MOD) % MOD;
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

    ll n;
    cin>>n;
    if(n == 0) return cout<<0, 0;

    matrix a, t;
    a.val[0][0] = 1;
    t.val[0][0] = t.val[0][1] = t.val[1][0] = 1;
    t = powmat(t, n - 1);
    matrix res = t * a;

    cout<<res.val[0][0];
    return 0;
}