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
int parent[maxn], sz[maxn];

void makeset(){
    for(int i = 1; i <=n ; i++){
        sz[i] = 1;
        parent[i] = i;
    }
    return;
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

    parent[v] = u;
    sz[u] += sz[v];
    sz[v] = 0;
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
    makeset();
    while(m--){
        int u, v;
        cin>>u>>v;
        unite(u, v);
    }

    int root = find(1);
    int sum = sz[root], maxx = 0;

    for(int i = 1; i <= n; i++)
        if(i != root) maxx = max(maxx, sz[i]);

    cout<<sum +maxx;
    return 0;
}