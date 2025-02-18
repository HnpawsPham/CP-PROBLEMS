#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e5 + 5;
vector<vector<int>> a(maxn);
int subsz[maxn], sz[maxn], parent[maxn];
bool check[maxn], isCen[maxn];
char res[maxn];

void makeSet(){
    for(int i = 1;i<=n;i++){
        sz[i] = 1;
        parent[i] = i;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unionSet(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    sz[b] = 0;
    return true;
}

int getSz(int u){
    int sz = 1;
    check[u] = 1;
    subsz[u] =1;

    for(int v : a[u]){
        if(check[v] || isCen[v]) continue;
        sz += getSz(v);
        subsz[u] += subsz[v];
    }

    return sz;
}

int initCen(int u, int p){
    bool ok = 1;
    check[u] = 1;
    int maxx = -1;

    for(int v : a[u]){
        if(check[v] || isCen[v]) continue;

        if(subsz[v] > p / 2) ok = 0;
        if(maxx == -1 || subsz[v] > subsz[maxx]) maxx = v;
    }

    if(ok && p - subsz[u] <= p / 2) return u;
    return initCen(maxx, p);
}

int getCen(int u){
    memset(check, 0, sizeof(check));

    int p = getSz(u);
    memset(check, 0, sizeof(check));

    int cen = initCen(u, p);
    isCen[cen] = 1;

    return cen;
}

int dcpTree(int u, int d){
    int cur = getCen(u);
    res[cur] = char('A' + d);
    // cout<<cur<<": "<<d<<el;

    for(int v : a[cur]) if(!isCen[v]) dcpTree(v, d + 1);

    return cur;
}

int main(){
    freopen(".\\txt\\GIAM-SAT-VUONG-QUOC.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    bool ok = 1;
    makeSet();

    for(int i =1;i<n;i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        if(!unionSet(u, v)) ok = 0;
    }

    if(!ok) {
        cout<<"Impossible!"<<el;
        return 0;
    }

    dcpTree(1, 0);
    for(int i = 1; i <=n;i++) cout<<res[i]<<" ";

    return 0;
}