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
    line(){};
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1){};

    bool operator<(const line& other) const {
        return w > other.w;
    }
};

int n, m;
const int maxn = 1e5 + 5;
const int LOG = 17;
const int oo = 1e6 + 7;
vector<line> ed;
vector<pii> a[maxn];
int parent[maxn], sz[maxn];
int p[maxn][LOG + 1], minn[maxn][LOG + 1], h[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
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

    parent[v] = u;
    sz[u] += sz[v];

    return 1;
}

void kruskal(){
    sort(ed.begin(), ed.end());

    int msz = 0;
    for(int i = 0; i < m; i++){
        if(unite(ed[i].u, ed[i].v)){
            msz++;
            a[ed[i].u].push_back({ed[i].w, ed[i].v});
            a[ed[i].v].push_back({ed[i].w, ed[i].u});
        }
        if(msz == n - 1) break;
    }
}

void dfs(int u, int par){
    for(auto [w, v] : a[u]){
        if(v == par) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        minn[v][0] = w;
        dfs(v, u);
    }
}

void prepare(){
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= LOG; j++)
            minn[i][j] = oo;

    h[0] = -1;
    dfs(1, 0);

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++){
            p[i][j] = p[p[i][j - 1]][j - 1];
            minn[i][j] = min(minn[i][j - 1], minn[p[i][j - 1]][j - 1]);
        }
}

int getmin(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    int res = oo;

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v]){
            res = min(res, minn[u][i]);
            u = p[u][i];
        }
    if(u == v) return res;

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] != p[v][i]){
            res = min(res, min(minn[u][i], minn[v][i]));
            u = p[u][i];
            v = p[v][i];
        }
    return min(res, min(minn[v][0], minn[u][0]));
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
        ed.push_back({u, v, w});
    }

    makeset();
    kruskal();
    prepare();

    ll res = 0;
    for(const line& x : ed)
        res += getmin(x.u, x.v) - x.w;
    cout<<res;
    return 0;
}