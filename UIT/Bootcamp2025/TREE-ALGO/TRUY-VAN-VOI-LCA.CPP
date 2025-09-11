#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int maxn = 3e5 + 5;
const int LOG = 19;

int n, q;
vector<int> a[maxn];
int p[maxn][LOG+1], h[maxn];

void dfs(int u){
    for(int v : a[u]){
        if(v == p[u][0]) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
    return;
}

void prepare(){
    h[0] = -1;
    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j-1]][j-1];
    return;
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v])
            u = p[u][i];

    if(u == v) return u;

    for(int i = LOG; i >= 0; i--){
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

int t[4 * maxn];

int calc(int u, int v){
    if(u == -1) return v;
    if(v == -1) return u;
    return lca(u, v);
}

void build(int i, int l, int r){
    if(l == r){
        t[i] = l;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = calc(t[2 * i], t[2 * i + 1]);
    return;
}

int query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return -1;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    return calc(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l, r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    p[1][0] = 0;
    dfs(1);
    prepare();

    build(1, 1, n);

    cin >> q;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<query(1, 1, n, l, r) << el;
    }
    return 0;
}
