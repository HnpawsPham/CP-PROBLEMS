#include <iostream>
#include <vector>
using namespace std;
#define el "\n"
#define LOG 18

int n, k, root;
const int maxn = 2e5 + 5;
vector<vector<int>> a(maxn), gr(maxn / 2);
int p[maxn][LOG + 1], h[maxn];

void dfs(int u){
    for(int v : a[u]){
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
        if(p[u][i] != p[v][i]){
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
    int maxx = 0, st = meet[0], mid = st;

    for(int x : meet){
        int dis = get_dis(st, x);
        if(maxx < dis){
            maxx = dis;
            mid = x;
        }
    }

    maxx = 0;

    for(int x : meet){
        int dis = get_dis(mid, x);
        maxx = max(maxx, dis);
    }

    return maxx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 1; i <= n; ++i){
        int x;
        cin>>x>>p[i][0];

        a[p[i][0]].push_back(i);
        gr[x].push_back(i);

        if(p[i][0] == 0) root = i;
    }
    
    dfs(root);
    h[0] = -1;

    for(int i = 1; i <= k; ++i)
        cout<<get_max(gr[i])<<el;

    return 0;
}