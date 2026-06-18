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

int n, m;
string lim;
int dp[10][2][2];

int dfs(int i, bool less, bool st, const vi& a){
    if(i == lim.size()) return st;

    if(dp[i][less][st] != -1) return dp[i][less][st];

    int res = 0;
    int maxx = lim[i] - '0';

    if(!st) res += dfs(i + 1, 1, 0, a);

    for(const int& x : a){
        if(!less && x > maxx) break;
        res += dfs(i + 1, (less || x < maxx), 1, a);
    }
    return dp[i][less][st] = res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vi a(m);
    for(int i = 0; i < m; i++) cin>>a[i];

    memset(dp, -1, sizeof dp);
    lim = to_string(n);
    cout<<dfs(0, 0, 0, a);
    return 0;
}

// 100 4
// 1 3 5 7