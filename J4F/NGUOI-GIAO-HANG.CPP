#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;
const int LOG = 18;
const int maxn = 2e5 + 5;
int w[maxn], p[maxn][LOG + 1], maxx[maxn][LOG + 1] = {0}, h[maxn];
vi a[maxn];

void dfs(int u){
    for(int v : a[u]){
        if(v == p[u][0]) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v);
    }
    return;
}

void prepare(){
    for(int i = 1; i <= n; i++)
        maxx[i][0] = w[i];

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++){
            maxx[i][j] = max(maxx[i][j - 1], maxx[p[i][j - 1]][j - 1]);
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    return;
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    int res = 0;

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v]){
            res = max(res, maxx[u][i]);
            u = p[u][i];
        }
    if(u == v) return max(res, w[u]);

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] != p[v][i]){
            res = max(res, max(maxx[u][i], maxx[v][i]));
            u = p[u][i];
            v = p[v][i];
        }

    res = max({res, w[u], w[v], w[p[u][0]]});
    return res;
}

int main(){
    // freopen("SHIP.inp", "r", stdin);
    // freopen("SHIP.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>w[i];

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    h[0] = -1;
    dfs(1);
    prepare();

    ll dp[n + 1];
    memset(dp, -1, sizeof dp);
    dp[1] = 0;

    cin>>k;
    while(k--){
        int u, v;
        cin>>u>>v;
        if(dp[u] == -1) continue;
        dp[v] = max(dp[v], dp[u] + lca(u, v));
    }
    cout<<*max_element(dp + 1, dp + n + 1);
    return 0;
}