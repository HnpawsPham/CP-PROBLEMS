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
    int u, v, w;
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};
    line() {};

    bool operator<(const line& other){
        return w < other.w;
    };
};

int n, m;
const int maxn = 1e4 + 5;
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

    if(u == v) return 1;
    if(sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
    return 0;
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
    vector<line> a(m);
    for(int i = 0; i < m; i++)
        cin>>a[i].u>>a[i].v>>a[i].w;
    sort(a.begin(), a.end());
    
    ll res = 0, cur;
    for(int i = 0; i < m; i++){
        makeset();

        for(int j = i; j < m; j++)
            if(unite(a[j].u, a[j].v)){
                if(a[i].w + a[j].w > res)
                    res = a[i].w + a[j].w; 
            }
    }
    cout<<res;
    return 0;
}