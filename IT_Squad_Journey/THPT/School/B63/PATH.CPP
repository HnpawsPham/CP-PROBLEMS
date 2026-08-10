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
#define taskname "PATH"

int n, m, s, t, U, V;
const int maxn = 1e5 + 5;
const ll oo = 1e15 + 5;
vector<pii> a[maxn];

vll dijkstra(int st){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vll dis(n + 1, oo);
    dis[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        for(auto [w1, v] : a[u]){
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

vi g[maxn];
bool check[maxn];
vi topo;

void dfs(int u){
    check[u] = 1;
    for(int v : g[u])
        if(!check[v]) dfs(v);
    topo.push_back(u);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s>>t>>U>>V;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    vll ds = dijkstra(s), dt = dijkstra(t);

    for(int u = 1; u <= n; u++)
        for(auto [w, v] : a[u]){
            if(ds[u] + w + dt[v] == ds[t])
                g[u].push_back(v);
        }

    memset(check, 0, sizeof check);
    for(int i = 1; i <= n; i++)
        if(!check[i]) dfs(i);
    reverse(topo.begin(), topo.end());

    vll du = dijkstra(U), dv = dijkstra(V);

    ll dp[n + 1][2], res = du[V]; 
    //0: x -> u, 1: x -> v
    for(int i = 1; i <= n; i++)
        dp[i][0] = dp[i][1] = oo;
    
    for(const int& x : topo){
        dp[x][0] = min(dp[x][0], du[x]);
        dp[x][1] = min(dp[x][1], dv[x]);

        for(const int& y : g[x]){
            dp[y][0] = min(dp[y][0], dp[x][0]);
            dp[y][1] = min(dp[y][1], dp[x][1]);
        }

        res = min(res, min(dp[x][0] + dv[x], dp[x][1] + du[x]));
    }
    cout<<res;
    return 0;
}