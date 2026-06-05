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

#define pll pair<ll, ll>

const int maxn = 18;
pll dp[maxn][maxn][maxn][2][2];
bool check[maxn][maxn][2][2];
string lim;

pll dfs(int i, int prev1, int prev2, bool less, bool st){
    if(i == lim.length()) 
        return {0, 0};

    if(check[i][prev1 + 1][prev2 + 1][less][st])
        return dp[i][prev1 + 1][prev2 + 1][less][st];

    int maxx = 9;
    if(!less) maxx = lim[i] - '0';

    pll res;
    for(int j = 0; j <= maxx; j++){
        int cnt = 0;
        if(!st || prev2 == -1) continue;
        
        if((prev1 > prev2 && prev2 < j)
        || (prev1 < prev2 && prev2 > j)) cnt = 1;

        bool less1 = less || (j < lim);
        bool st1 = (j > 0) || st;
        pll next = dfs(i + 1, (st1 ? j : -1), (st1 ? prev1 : -1), less1, st1);

        res.fi += next.fi;
        res.se += next.se + cnt * next.fi;
    }

    check[i][prev1][prev2][less][st] = 1;
    return dp[i][prev1][prev2][less][st] = res;
}

ll sol(ll n){
    if(n <= 100) return 0;
    lim = to_string(n);
    memset(check, 0, sizeof check);
    return dfs(0, -1, -1, 0, 0);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    cin>>l>>r;
    cout<<sol(r) - sol(l - 1);
    return 0;
}