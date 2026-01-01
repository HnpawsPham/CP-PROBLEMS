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

struct line{
    int u, v, w;
    bool inMST = 0;
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};

    bool operator<(const line& other) const{
        return w < other.w;
    }
};

int n, m;
ll d = 0;
const int maxn = 2e5 + 5;
const int LOG = 18;
int sz[maxn], parent[maxn], p[maxn][LOG + 1], maxx[maxn][LOG + 1], h[maxn];
vector<line> a;
vector<pii> g[maxn];

void dfs(int u){
    for(auto [w, v] : g[u]){
        if(v == p[u][0]) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        maxx[v][0] = w;
        dfs(v);
    }
    return;
}

void prepare(){
    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++){
            p[i][j] = p[p[i][j - 1]][j - 1];
            maxx[i][j] = max(maxx[i][j - 1], maxx[p[i][j - 1]][j - 1]);
        }
    h[0] = -1;
    return;
}

int lca(int u, int v){
    int res = 0;
    if(h[u] < h[v]) swap(u, v); 

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v]){
            res = max(res, maxx[u][i]);
            u = p[u][i];
        }
    if(u == v) return res;

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] != p[v][i]){
            res = max(res, maxx[u][i]);
            res = max(res, maxx[v][i]);
            u = p[u][i];
            v = p[v][i];
        }
    return max(max(res, maxx[u][0]), maxx[v][0]);
}

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= LOG; j++)
            maxx[i][j] = 0;
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

void kruskal(vector<line> a){
    sort(a.begin(), a.end());
    int msz = 0;

    for(line& x : a){
        if(msz == n - 1) break;

        if(unite(x.u, x.v)){
            d += x.w;
            x.inMST = 1;

            g[x.u].push_back({x.w, x.v});
            g[x.v].push_back({x.w, x.u});
            msz++;
        }
    }
    return;
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

    makeset();
    kruskal(a);
    p[1][0] = 0;
    dfs(1);
    prepare();

    for(int i = 0; i < m; i++)
        if(a[i].inMST) cout<<d<<el;
        else cout<<d + a[i].w - lca(a[i].v, a[i]. u)<<el;
    return 0;
}