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

int n, q;
const int maxn = 3e5 + 5;
const int LOG = 20;
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

int findKth(int u, int k){
    for(int i = 0; i <= LOG; i++)
        if((k >> i) & 1) u = p[u][i];
    return u;
}

void prepare(){
    h[1] = 0;
    p[1][0] = 0;
    dfs(1);
    
    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    return;
};

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i>= 0; i--)
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
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    prepare();

    cin>>q;
    while(q--){
        int u, v, w;
        cin>>u>>v>>w;
        int g = lca(u, v);
        int dis = h[u] + h[v] - 2 * h[g];

        if(w >= dis) cout<<v<<el;
        else if(w <= h[u] - h[g]) cout<<findKth(u, w)<<el;
        else cout<<findKth(v, dis - w)<<el;
    }
    return 0;
}