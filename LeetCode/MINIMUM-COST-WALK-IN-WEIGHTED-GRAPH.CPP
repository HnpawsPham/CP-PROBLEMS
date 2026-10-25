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

int n;
const int maxn = 1e5 + 5;
int sz[maxn], parent[maxn], sum[maxn];

void makeset(){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        sum[i] = -1;
        sz[i] = 1;
    }
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void add(int &x, int d){
    if(d == -1) return;
    if(x == -1) x = d;
    else x &= d;
}

bool unite(int u, int v, int w){
    u = find(u);
    v = find(v);

    if(u == v){
        add(sum[u], w);
        return 0;
    }
    if(sz[u] < sz[v]) swap(u, v);

    sz[u] += sz[v];
    add(sum[u], sum[v]);
    parent[v] = u;

    add(sum[u], w);
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

    int m, k;
    cin>>n>>m>>k;
    vector<vi> ed(m, vi(3)), q(k, vi(2));
    for(int i = 0; i < m; i++)
        cin>>ed[i][0]>>ed[i][1]>>ed[i][2];

    for(int i = 0; i < k; i++)
        cin>>q[i][0]>>q[i][1];

    makeset();
    for(const vi& v : ed)
        unite(v[0], v[1], v[2]);

    vi res;
    for(const vi& v : q){
        if(find(v[0]) != find(v[1])) 
            res.push_back(-1);
        else res.push_back(sum[find(v[0])]);
    }
    for(const int& x : res) cout<<x<<" ";
    return 0;
}

// 5 3 2
// 0 1 7
// 1 3 7
// 1 2 1
// 0 3
// 3 4