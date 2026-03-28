#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<ll, pii>
#define fi first
#define se second
//#define taskname ""

int n, m, k, s, t;
const int maxn = 1e5 + 5;
const ll oo = 1e15 + 16;
vector<pii> a[maxn];

ll dijkstra(){
    vector<vll> dis(n + 1, vll(k + 1, oo));
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    dis[s][k] = 0;
    pq.push({0, {k, s}});

    while(!pq.empty()){
        auto [w, cur] = pq.top();
        auto [cnt, u] = cur;
        pq.pop();

        if(w > dis[u][cnt]) continue;

        if(cnt > 0){
            for(auto [w1, v] : a[u])
                if(dis[v][cnt - 1] > dis[u][cnt]){
                    dis[v][cnt - 1] = dis[u][cnt];
                    pq.push({dis[v][cnt - 1], {cnt - 1, v}});
                }
        }
        for(auto [w1, v] : a[u])
            if(dis[v][cnt] > dis[u][cnt] + w1){
                dis[v][cnt] = dis[u][cnt] + w1;
                pq.push({dis[v][cnt], {cnt, v}});
            }
    }
    return dis[t][0];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k>>s>>t;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    cout<<dijkstra();
    return 0;
}