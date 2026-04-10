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
#define taskname "BANHKEO"

int n, m, k;
const int maxn = 1005;
int parent[maxn], sz[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
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

    cin>>n>>m>>k;
    int minp = 505;
    while(k--){
        int x;
        cin>>x;
        minp = min(minp, x);
    }
  
    makeset();
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        if(w >= minp) unite(u, v);
    }
 
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        cnt += (sz[i] > 0);
    cout<<cnt;
    return 0;
}