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
//#define taskname ""

int n, m;
const int maxn = 1e5 + 5;
const ll oo = 1e15 + 5;
vector<pii> a[maxn];
vi dag[maxn];

vll dijkstra(int st){
    vll dis(n + 1, oo);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dis[st] = 0;
    pq.push({0, st});

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

vi topo;
bool check[maxn] = {0};

void dfs(int u){
    check[u] = 1;

    for(int v : dag[u])
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

    int A, B, C, D;
    cin>>n>>m>>A>>B>>C>>D;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    vll dA = dijkstra(A), dB = dijkstra(B),
    dC = dijkstra(C), dD = dijkstra(D);

    for(int u = 1; u <= n; u++)
        for(auto [w, v] : a[u])
            if(dA[u] + w + dB[v] == dA[B])    
                dag[u].push_back(v);

    for(int i = 1; i <= n; i++)
        if(!check[i]) dfs(i);

    vector<vll> dp(2, vll(n + 1, oo));
    for(int i = 1; i <= n; i++)
        dp[0][i] = dp[1][i] = dC[i];

    for(int u : topo)
        for(int v : dag[u])
            dp[1][u] = min(dp[1][v], dp[1][u]);
    reverse(topo.begin(), topo.end());
    
    for(int u : topo)
        for(int v : dag[u])
            dp[0][v] = min(dp[0][v], dp[0][u]);
  
    ll res = dC[D];
    for(int i = 1; i <= n; i++)
        res = min(res, min(dp[0][i] + dD[i], dp[1][i] + dD[i]));
    cout<<res;
    return 0;
}