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

int n, m, st;
const int maxn = 1e5 + 5;
int parent[maxn], sz[maxn];

void makeset(){
    for(int i = 0; i < n; i++){
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

    sz[u] += sz[v];
    parent[v] = u;
    return 1;
}

void reset(int x){
    parent[x] = x;
    sz[x] = 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>st;
    vector<vi> ed;
    while(m--){
        int u, v, t;
        cin>>u>>v>>t;
        ed.push_back({u, v, t});
    }

    map<int, vector<pii>> mp;
    for(const vi& v : ed)
        mp[v[2]].push_back({v[0], v[1]});

    makeset();
    unite(0, st);

    for(auto [t, meet] : mp){
        for(auto [u, v] : meet)
            unite(u, v);
        
        for(auto [u, v] : meet)
            if(find(u) != find(0)){
                reset(u);
                reset(v);
            }
    }

    vi res;
    for(int i = 0; i < n; i++)
        if(find(i) == find(0))
            res.push_back(i);
    
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 6 3 1
// 1 2 5
// 2 3 8
// 1 5 10