#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define LOG 19

int n, m, q;
const int maxn = 3 * (1e5) + 5;
vector<vector<int>> a(maxn);
int h[maxn], parent[maxn];

// O(n)
void dfs1(int u){
    for(int v : a[u]){
        if(v == parent[u]) continue;
        parent[v] = u;
        h[v] = h[u] + 1;
        dfs1(v);
    }
    return;
}

int lca(int u, int v){
    if(h[v] > h[u]) swap(u, v);

    while(h[u] > h[v]) 
    u = parent[u];

    while(u != v){
        u = parent[u];
        v = parent[v];
    }
    return u;
}

// O(log N)
int p[maxn][LOG + 1];

void dfs2(int u){
    for(int v : a[u]){
        if(v == p[u][0]) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs2(v);
    }
    return;
}

void prepare(){
    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    h[0] = -1;
    return;
}

int _lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v])
            u = p[u][i];
    if (u == v) return u;
    
    for(int i = LOG; i >=0 ; i--)
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

    cin>>n>>m>>q;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    p[1][0] = 0;
    dfs2(1);
    prepare();

    while(q--){
        int u, v;
        cin>>u>>v;
        cout<<_lca(u, v)<<el;
    }

    return 0;
}
// 6
// 5
// 3
// 1 2
// 2 4
// 2 5
// 1 3
// 3 6
// 2 5
// 4 6
// 4 3