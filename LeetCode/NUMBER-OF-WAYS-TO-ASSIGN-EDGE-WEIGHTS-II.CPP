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

int n;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
const int LOG = 17;
vi a[maxn];
int p[maxn][LOG + 1], h[maxn];

void prepare(){
    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    return;
}

void dfs(int u, int parent){
    for(int v : a[u]){
        if(v == parent) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
    return;
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

int ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * 1LL * a % MOD;
    return half * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>n>>m;
    vector<vi> ed(n - 1, vi(2)), q(m, vi(2));
    for(int i = 0; i < n - 1; i++)
        cin>>ed[i][0]>>ed[i][1];

    for(int i = 0; i < m; i++)
        cin>>q[i][0]>>q[i][1];

    for(const vi& v : ed){
        a[v[0]].push_back(v[1]);
        a[v[1]].push_back(v[0]);
    }

    h[1] = 0;
    dfs(1, 0);
    prepare();

    vi res;
    for(const vi& v : q){
        if(v[0] == v[1]){
            res.push_back(0);
            continue;
        }

        int d = h[v[0]] + h[v[1]] - 2 * h[lca(v[0], v[1])];
        res.push_back(ppow(2, d - 1));
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 2 2
// 1 2
// 1 1
// 1 2