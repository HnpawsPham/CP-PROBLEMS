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

int n;
string lim;
pll dp[12][2][2];
bool check[12][2][2];

pll dfs(int i, bool st, bool less){
    if(i == lim.length()) 
        return {st, 0};

    if(check[i][st][less])
        return dp[i][st][less];

    int maxx = 9;
    if(!less) maxx = lim[i] - '0';

    pll res = {0, 0};
    for(int j = 0; j <= maxx; j++){
        pll next = dfs(i + 1, st || (j > 0), less || (j < maxx));
        res.fi += next.fi;
        res.se += next.se + next.fi * (j == 1);
    }

    check[i][st][less] = 1;
    return dp[i][st][less] = res;
}

ll sol(int x){
    memset(check, 0, sizeof check);
    lim = to_string(x);
    return dfs(0, 0, 0).se;
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
    cout<<sol(n);
    return 0;
}