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

int n, m;
const int maxn = 1e5 + 5;
int a[maxn];
int parent[maxn], sz[maxn], minn[maxn];

void makeset(){
    for(int i = 1; i<= n; i++){
        parent[i] = i;
        minn[i] = a[i];
        sz[i] = 1;
    }
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;
    if(sz[u] < sz[v]) swap(u, v);

    minn[u] = min(minn[u], minn[v]);
    parent[v] = u;
    sz[u] += sz[v];
    return 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    makeset();
    while(m--){
        int u, v;
        cin>>u>>v;
        unite(u, v);
    }

    ll res = 0;
    for(int i = 1; i <= n; i++)
        if(i == find(i)) res += minn[i];
    cout<<res; 
    return 0;
}