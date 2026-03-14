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
#define taskname "THAMQUAN"

int n, m, q;
const int maxn = 1005;
vector<pii> a[maxn];

vi dijkstra(){
    priority_queue<pii, vector<pii>> pq;
    vi dis(n + 1, -1);
    dis[1] = 1e5 + 5;
    pq.push({dis[1], 1});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w < dis[u]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[v] < min(dis[u], w1)){
                dis[v] = min(dis[u], w1);
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
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
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    vi dis = dijkstra();
    while(q--){
        int x;
        cin>>x;
        cout<<dis[x]<<el;
    }
    return 0;
}