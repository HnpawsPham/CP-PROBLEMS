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

struct line{
    int u, v;
    bool del = 0;
    line(int u1, int v1) : u(u1), v(v1) {};
    line() {};
};

int n, m, q;
const int maxn = 1e5 + 5;
vector<line> a;
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

    sz[u] += sz[v];
    parent[v] = u;
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

    cin>>n>>m>>q;
    makeset();

    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        a.push_back({u, v});
    }

    vi delEd;
    for(int i = 0; i < q; i++){
        int x;
        cin>>x;
        a[x - 1].del = 1;
        delEd.push_back(x - 1);
    }

    int comp = n;
    for(int i = 0; i < m; i++)
        if(!a[i].del && unite(a[i].u, a[i].v)) 
            comp--;

    vi res;
    for(int i = q - 1; i >= 0; i--){
        res.push_back(comp);
        if(unite(a[delEd[i]].u, a[delEd[i]].v)) comp--;
    }

    for(int i = q - 1; i >= 0; i--) 
        cout<<res[i]<<el;
    return 0;
}