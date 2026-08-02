#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

const ll oo = 1e18 + 5;
map<pll, pll> dp;

pll sol(ll n, int maxx){
    if(n == 0) return {0, 0};
    if(n < 10) return {1, n - max(n, 1LL * maxx)};

    if(dp.find({n, maxx}) != dp.end())
        return dp[{n, maxx}];

    ll base = 1;
    while(base <= n / 10) base *= 10;

    ll x = n;
    pll res = {0, 0};
    while(x > 0){
        int cur = x / base;
        pll tmp;
        if(x % base)
            tmp = sol(x % base, max(cur, maxx));  
        else tmp = {1, -max(maxx, cur)};

        res.fi += tmp.fi;
        x = cur * base + tmp.se;
        res.se = x;
    }
    return dp[{n, maxx}] = res;
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
    cout<<sol(n, 0).fi;
    return 0;
}