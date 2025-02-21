#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second
#define LOG 10

int n, q;
const int maxn = 1001;
vector<vector<pii>> a(maxn);
int h[maxn], parent[maxn][LOG + 1];
ll dp[maxn];

void dfs(int u){
    for(pii x : a[u]){
        int v = x.se;
        int w = x.fi;

        if(v == parent[u][0]) continue;

        h[v] = h[u] + 1;
        dp[v] = dp[u] + w;
        parent[v][0] = u;
        dfs(v);
    }
    return;
}

void prepare(){
    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
    
    h[0] = -1;
    return;
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i>=0; i--)
        if(h[parent[u][i]] >= h[v])
            u = parent[u][i];
    if(u == v) return u;

    for(int i = LOG; i>= 0; i--)
        if(parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    return parent[u][0];
}

ll get_dis(int u, int v){
    int _lca = lca(u, v);
    return 1LL * dp[u] + dp[v] - 2 * dp[_lca];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    parent[1][0] = 0;
    dfs(1);
    prepare();

    while(q--){
        int u, v;
        cin>>u>>v;
        cout<<get_dis(u, v)<<el;
    }
    return 0;
}