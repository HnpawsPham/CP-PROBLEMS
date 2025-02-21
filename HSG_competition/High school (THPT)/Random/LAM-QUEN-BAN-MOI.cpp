#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define LOG 18

int n, k, root;
const int maxn = 2 * (int)1e5 + 5;
vector<vector<int>> a(maxn), gr(maxn / 2);
int p[maxn][LOG + 1], h[maxn];

void dfs(int u){
    for(int v : a[u]){
        if(v == p[u][0]) continue;

        h[v] = h[u] + 1;

        for(int i = 1; i < LOG; i++)
            p[v][i] = p[p[v][i - 1]][i - 1];
        dfs(v);
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
        if(h[p[u][i]] != h[p[v][i]]){
            u = p[u][i];
            v = p[v][i];
        }

    return p[u][0];
}

int get_dis(int u, int v){
    int _lca = lca(u, v);
    return h[u] + h[v] - 2 * h[_lca];
}

int get_max(vector<int> &meet){
    int maxx = 0, st = meet[0], mid = st, dis;
    return maxx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x>>p[i][0];

        a[p[i][0]].push_back(i);
        gr[x].push_back(i);

        if(p[i][0] == 0) root = i;
    }

    return 0;
}