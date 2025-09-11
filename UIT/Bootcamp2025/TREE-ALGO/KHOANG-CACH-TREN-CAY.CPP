#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int sub, n, q;
const int maxn = 3e5 + 5;
const int LOG = 19;
int p[maxn][LOG + 1], h[maxn];
ll dis[maxn] = {0};
vector<pii> a[maxn];

void dfs(int u){
    for(auto [w, v] : a[u]){
        if(v == p[u][0]) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dis[v] = dis[u] + w;
        dfs(v);
    }
    return;
}

void prepare(){
    h[0] = -1;
    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>sub>>n;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    p[1][0] = 0;
    dfs(1);
    prepare();

    cin>>q;
    while(q--){
        int u, v;
        cin>>u>>v;
        cout<<1LL * dis[u] + dis[v] - 2LL * dis[lca(u, v)]<<el;
    }
    return 0;
}