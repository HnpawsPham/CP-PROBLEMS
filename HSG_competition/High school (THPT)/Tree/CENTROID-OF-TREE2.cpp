#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e5 + 5;
vector<vector<int>> a(maxn), cen_tree(maxn);
bool check[maxn], isCen[maxn];
int subsz[maxn];

int getSz(int u){
    int sz = 1;
    check[u] = 1;
    subsz[u] = 1;

    for(int v : a[u]){
        if(check[v] || isCen[v]) continue;
        sz += getSz(v);
        subsz[u] += subsz[v];
    }

    return sz;
}

int initCen(int u, int n){
    bool ok = 1;
    check[u] = 1;
    int maxx = -1;

    for(int v : a[u]){
        if(check[v] || isCen[v]) continue;

        if(subsz[v] > n / 2) ok = 0;
        if(maxx == -1 || subsz[v] > subsz[maxx]) maxx = v;
    }

    if(ok && n - subsz[u] <= n / 2) return u;
    return initCen(maxx, n);
}

int getCen(int u){
    memset(subsz, 0, sizeof(subsz));
    memset(check, 0, sizeof(check));

    int n = getSz(u);
    memset(check, 0, sizeof(check));

    int cen = initCen(u, n);
    isCen[cen] = 1;
    return cen;
}

int dcpTree(int u){
    int cur = getCen(u);
    cout<<cur<<" ";

    for(int v : a[cur]){
        if(isCen[v]) continue;

        int sub = dcpTree(v);

        cen_tree[cur].push_back(sub);
        cen_tree[sub].push_back(cur);
    }
    return cur;
}

int main(){
    freopen(".\\INPUT.INP", "r", stdin);
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

    dcpTree(1);

    return 0;
}