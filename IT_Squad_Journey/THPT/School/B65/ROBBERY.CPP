#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
#define taskname "ROBBERY"

int n, m;
const int maxn = 2e5 + 5;
const ll oo = 1e17 + 5;
int cost[maxn], type[maxn];
vector<pii> a[3 * maxn];

void dijkstra(){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vll dis(maxn * 3, oo);
    dis[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;
        if(u == n) break;

        for(auto [w1, v] : a[u]){
            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    cout<<dis[n];
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
    memset(cost, 0, sizeof cost);
    memset(type, 0, sizeof type);
    for(int i = 1; i <= n; i++) cin>>cost[i];
    for(int i = 1; i <= n; i++) cin>>type[i];
  
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    int en = 2e5;
    int in = n + 2;
    int out = n + en + 3;

    for(int i = 0; i < en; i++){
        a[in + i + 1].push_back({0, in + i});
        a[out + i].push_back({0, out + i + 1});
    }
 
    for(int i = 1; i <= n; i++){
        if(type[i] == 1 || type[i] == 3){
            a[i].push_back({cost[i], n + 1});
            a[n + 1].push_back({cost[i], i});
        }
        if(type[i] == 3 || type[i] == 2){
            a[i].push_back({0, cost[i] + in});
            a[cost[i] + in].push_back({cost[i], i});

            a[i].push_back({cost[i], cost[i] + out});
            a[cost[i] + out].push_back({0, i});
        }
    }
    dijkstra();
    return 0;
}

// 5 4 
// 1 8 3 4 1 
// 0 1 3 2 0 
// 1 3 7 
// 2 4 5 
// 4 3 6 
// 2 5 10

// 5 4 
// 1 4 3 4 1 
// 0 1 3 2 0 
// 1 3 7 
// 2 4 5 
// 4 3 6
// 2 5 10