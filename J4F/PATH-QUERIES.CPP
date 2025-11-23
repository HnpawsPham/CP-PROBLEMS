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

int n, q;
const int maxn = 1e5 + 5;
const int LOG = 17;
vi a[maxn];
int p[maxn][LOG + 1], h[maxn] = {0};

void dfs(int u){
    for(int v : a[u]){
        if(v == p[u][0]) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
    return;
}

void build(){
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

    cin>>n>>q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    h[1] = 0;
    p[1][0] = 0;
    dfs(1);
    build();

    while(q--){
        int x, y, z;
        cin>>x>>y>>z;
        int xy = lca(x, y), yz = lca(y, z), xz = lca(x, z);

        if((xz == xy && yz == y) || (xz == yz && xy == y)) cout<<"YES"<<el;
        else cout<<"NO"<<el;
    }
    return 0;
}

// 5 3
// 1 2
// 2 3
// 2 4
// 1 5
// 1 2 3
// 2 3 4
// 4 2 1