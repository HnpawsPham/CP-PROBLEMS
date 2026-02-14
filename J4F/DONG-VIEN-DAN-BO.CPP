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

    bool operator<(const line& other) const{
        return w < other.w;
    }
};

int n, m;
const int maxn = 1e4 + 5;
vector<line> a;
int parent[maxn], sz[maxn];
int c[maxn];

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
    return 1;
}

int kruskal(){
    sort(a.begin(), a.end());
    int msz = 0, d = 0;

    for(const line& x : a){
        if(msz == n - 1) break;

        if(unite(x.u, x.v)){
            d += x.w;
            msz++;
        }
    }
    return d;
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
    for(int i = 1; i<= n; i++) cin>>c[i];
    makeset();

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a.push_back({u, v, 2 * w + c[u] + c[v]});
    }

    cout<<kruskal() + *min_element(c + 1, c + n + 1);
    return 0;
}