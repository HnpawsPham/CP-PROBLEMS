#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
#define taskname "DDDB"

int n, m, k;
const int maxn = 1e5 + 5;
const ll oo = 1e15 + 5;
vector<pii> a[maxn];
int special[maxn];

vll dijkstra(int st){
    vll dis(n + 1, oo);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, st});
    dis[st] = 0;

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

namespace sub2{
    ll sol(){
        ll dis[k + 1][k + 1];
        for(int i = 0; i < k; i++){
            vll d = dijkstra(special[i]);

            for(int j = 0; j < k; j++)
                dis[i][j] = d[special[j]];
        }

        int v[k];
        for(int i = 0; i < k; i++) v[i] = i;

        ll res = oo;
        do{
            ll tmp = 0;
            for(int i = 1; i < k; i++){
                ll minn = oo;

                for(int j = 0; j < i; j++)
                    minn = min(minn, dis[v[j]][v[i]]);
                tmp += minn;
            }
            res = min(res, tmp);
        } while(next_permutation(v, v + k));

        return res;
    }
}

namespace sub3{
    struct line{
        int u, v, w;
        line() {};
        line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};

        bool operator<(const line& other){
            return w < other.w;
        }
    };

    vector<line> ed;
    int parent[maxn], sz[maxn];

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

        parent[v] = u;
        sz[u] += sz[v];
        return 1;
    }

    ll sol(){
        makeset();
        sort(ed.begin(), ed.end());
        
        int msz = 0;
        ll d = 0;

        for(int i = 0; i < m; i++){
            if(unite(ed[i].u, ed[i].v)){
                d += ed[i].w;
                msz++;
            }

            if(msz == n - 1) break;
        }
        return d;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i = 0; i < k; i++) cin>>special[i];

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
        sub3::ed.push_back({u, v, w});
    }

    if(k == n) cout<<sub3::sol();
    else cout<<sub2::sol();
    return 0;
}