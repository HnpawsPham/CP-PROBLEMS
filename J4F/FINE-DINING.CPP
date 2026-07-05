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

int n, m, k;
const int maxn = 5e4 + 5;
const ll oo = 1e9 + 5; 
vector<pii> a[maxn];

vi dijkstra(int st){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dis(n + 1, oo);
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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    vi disS = dijkstra(n);

    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vll disT(n + 1, 1e14 + 5);

    while(k--){
        int x, y;
        cin>>x>>y;
        disT[x] = disS[x] - y;
        pq.push({disT[x], x});
    }

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > disT[u]) continue;

        for(auto [w1, v] : a[u]){
            if(disT[v] > disT[u] + w1){
                disT[v] = disT[u] + w1;
                pq.push({disT[v], v});
            }
        }
    }
    
    for(int i = 1; i < n; i++)
        cout<<(disT[i] <= disS[i])<<el;
    return 0;
}