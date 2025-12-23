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
const int maxn = 2e5 + 5;
const ll oo = 1e15 + 5;

vll dijkstra(const vector<vector<pii>>& a){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vll dis(n + 1, oo);
    dis[1] = 0;
    pq.push({0, 1});

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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vector<pii>> a(n + 1), ra(n + 1);
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        ra[v].push_back({w, u});
    }
    vll dis = dijkstra(a), rdis = dijkstra(ra);
    for(int i = 2; i <= n; i++)
        if(dis[i] != oo && rdis[i] != oo)
            cout<<1LL * dis[i] + rdis[i]<<el;
        else cout<<-1<<el;
    return 0;
}