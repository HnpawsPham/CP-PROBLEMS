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

struct pos{
    int u, v, w;
    pos(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};

    bool operator<(const pos& other) const{
        return w < other.w;
    }
};

int n;
const int maxn = 3e3 + 5;
vector<pos> a;
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

void kruskal(){
    sort(a.begin(), a.end());
    int msz = 0;
    ll d = 0;

    for(const pos& x : a){
        if(msz == n - 1) break;
        
        if(unite(x.u, x.v)){
            d += x.w;
            msz++;
        }
    }
    cout<<d;
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

    cin>>n;
    vector<vi> ed(n, vi(3));
    for(int i = 0; i < n; i++)
        cin>>ed[i][0]>>ed[i][1]>>ed[i][2];

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            a.push_back({i, j, 
            min(abs(ed[i][0] - ed[j][0]), 
            min(abs(ed[i][1] - ed[j][1]), abs(ed[i][2] - ed[j][2])))});

    makeset();
    kruskal();
    return 0;
}