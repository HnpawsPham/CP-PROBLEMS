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
    for(int i = 0; i < n; i++){
        sz[i] = 1;
        parent[i] = i;
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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int d, k;
    cin>>n>>m>>d>>k;
    int a[m];
    for(int i = 0; i < m; i++) cin>>a[i];


    vector<vi> q(k, vi(2));
    for(int i = 0; i < k; i++) 
        cin>>q[i][0]>>q[i][1];

    makeset();
    for(int i = 1; i < n; i++)
        if(a[i] - a[i - 1] <= d) 
            unite(i, i - 1);

    vector<bool> res;
    for(const vi& v : q)
        if(find(v[0]) == find(v[1]))
            res.push_back(1);
        else res.push_back(0);
    
    for(bool x: res) cout<<x<<" ";
    return 0;
}

// 2 2 1 2
// 1 3
// 0 0 
// 0 1