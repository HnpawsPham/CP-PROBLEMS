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
const int maxn = 1005;
int parent[maxn], sz[maxn];
vector<pii> ed;

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
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

    sz[u] += sz[v];
    parent[v] = u;
    return 1;
}

vector<pii> res, tmp;
int cnt = 0;

void kruskal(int skip){
    int msz = 0;
    makeset();

    for(int i = 0; i < m; i++){
        if(i == skip) continue;

        if(unite(ed[i].fi, ed[i].se)){
            msz++;
            tmp.push_back(ed[i]);
        }
        if(msz == n - 1) break;
    }

    if(msz == n - 1){
        for(const pii& x : tmp)
            res.push_back(x);
        cnt++;
    }
    tmp.clear();
    return;
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
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        ed.push_back({u, v});
    }
    
    for(int i = 0; i < m && cnt != 3; i++) 
        kruskal(i);

    cout<<cnt<<el;
    for(const pii& x : res)
        cout<<x.fi<<" "<<x.se<<el;
    return 0;
}