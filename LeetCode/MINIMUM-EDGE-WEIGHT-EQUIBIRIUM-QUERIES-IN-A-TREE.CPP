#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, root = 1;
const int maxn = 1e4 + 5;
const int LOG = 14;
vector<pii> a[maxn];
int p[maxn][LOG + 1];
int h[maxn] = {0};
vector<vi> cnt(maxn, vi(27, 0));

void dfs(int u){
    for(auto [_, v] : a[u]){
        if(v == p[u][0]) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
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

void dfs2(int u){
    for(auto [w, v] : a[u]){
        if(v == p[u][0]) continue;
        cnt[v] = cnt[u];
        cnt[v][w]++;
        dfs2(v);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> ed(n - 1, vi(3));
    for(int i = 0; i < n - 1; i++) {
        cin>>ed[i][0]>>ed[i][1]>>ed[i][2];
        ed[i][0]++;
        ed[i][1]++;
    }

    vector<vi> que(m, vi(2));
    for(int i = 0; i < m; i++) cin>>que[i][0]>>que[i][1];

    for(const auto& e : ed){
        a[e[0]].push_back({e[2], e[1]});
        a[e[1]].push_back({e[2], e[0]});
    }

    h[root] = 0;

    dfs(root);
    prepare();

    for(auto [w, v] : a[root]){
        cnt[v][w] = 1;
        dfs2(v);
    }
    
    vi res;
    for(const auto& q : que){
        int u = q[0], v = q[1];
        int parent = lca(u, v);
        int x = 0, ednum = h[u] + h[v] - 2 * h[parent];

        for(int w = 0; w < 27; w++)
            x = max(cnt[u][w] + cnt[v][w] - cnt[parent][w] * 2, x);

        res.push_back(ednum - x);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 7 4
// 0 1 1
// 1 2 1
// 2 3 1
// 3 4 2
// 4 5 2
// 5 6 2
// 0 3
// 3 6
// 2 6
// 0 6