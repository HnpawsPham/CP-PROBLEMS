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

struct edge{
    int u, v, w;
    edge(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};
    edge() {}; 

    bool operator<(const edge& other) const{
        return w < other.w;
    }
};

int n, m;
const int maxn = 2e5 + 5;
const int LOG = 18;
const ll oo = 1e17 + 5;
vector<edge> a, b;
vector<pii> g[maxn];
int parent[maxn], sz[maxn], h[maxn], maxx[maxn][LOG + 1] = {0}, p[maxn][LOG + 1] = {0};

void dfs(int u){
    for(auto [w, v] : g[u]){
        if(v == p[u][0]) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        maxx[v][0] = w;
        dfs(v);
    }
    return;
}

void prep(){
    h[0] = -1;
    p[1][0] = 0;
    maxx[1][0] = 0;
    dfs(1);

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++){
            p[i][j] = p[p[i][j - 1]][j - 1];
            maxx[i][j] = max(maxx[i][j - 1], maxx[p[i][j - 1]][j - 1]);
        }
    return;
}

int lca(int u, int v){
    int res = 0;
    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] > 0 && h[p[u][i]] >= h[v]){
            res = max(res, maxx[u][i]);
            u = p[u][i];
        }
    if(u == v) return res;

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] != p[v][i]){
            res = max(res, max(maxx[v][i], maxx[u][i]));
            u = p[u][i];
            v = p[v][i];
        }
    
    res = max(res, max(maxx[v][0], maxx[u][0]));
    return res;
}

void makeset(){
    for(int i = 1; i <= n ; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;
    if(sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;
    return 1;
}

ll kruskal(){
    makeset();
    int msz = 0;
    ll d = 0;

    for(int i = 0; i < m; i++){
        if(msz == n - 1) break;

        if(unite(a[i].u, a[i].v)){
            msz++;
            d += a[i].w;
            g[a[i].u].push_back({a[i].w, a[i].v});
            g[a[i].v].push_back({a[i].w, a[i].u});
        }
    }
    return d;
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
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a.push_back({u, v, w});
    }
    b = a;
    sort(a.begin(), a.end());

    ll mst = kruskal();
    prep();

    for(int i = 0; i < m; i++)
        cout<<mst + 1LL * b[i].w - lca(b[i].u, b[i].v)<<el;
    return 0;
}