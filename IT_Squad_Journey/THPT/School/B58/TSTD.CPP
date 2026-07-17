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
#define taskname "TSTD"

int n;
const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;
const int LOG = 20;
vi a[maxn];
int h[maxn], p[maxn][LOG + 1], w[maxn], wanc[maxn];

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
    h[0] = -1;
    dfs(1);

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v])
            u = p[u][i];
    if(u == v) return u;

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
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
    for(int i = 1; i <= n; i++) cin>>w[i];
    for(int i = 1; i <= n; i++) cin>>wanc[i];

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    prepare();

    ll res = 0;
    for(ll i = 1; i < (1 << n); i++){
        ll mul = 1;
        int common = -1;
        for(int j = 1; j <= n; j++)
            if((i >> (j - 1)) & 1){
                mul = mul * w[j] % MOD;
                if(common == -1) common = j;
                else common = lca(common, j);
            }
        res = (res + mul * wanc[common] % MOD) % MOD; 
    }
    cout<<res;
    return 0;
}