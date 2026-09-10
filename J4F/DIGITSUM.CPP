#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
//#define taskname ""

pll dp[18][2]; //len, less
string lim = "";

pll dfs(int i, bool less){
    if(i == lim.size()) return {0, 1};

    if(dp[i][less].se != -1)
        return dp[i][less];

    int maxx = 9;
    if(!less) maxx = lim[i] - '0';

    pll res = {0, 0};
    for(int j = 0; j <= maxx; j++){
        pll tmp = dfs(i + 1, less || j < maxx);
        res.fi += tmp.fi + tmp.se * j;
        res.se += tmp.se;
    }
    return dp[i][less] = res;
}

ll sol(ll x){
    if(x < 0) return 0;
    for(int i = 0; i < 18; i++)
        dp[i][0] = dp[i][1] = {0, -1};

    lim = to_string(x);
    return dfs(0, 0).fi;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b;
    cin>>a>>b;
    cout<<sol(b) - sol(a - 1);
    return 0;
}