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

int n, k, m;
const int maxn = 505;
const int oo = 1e9 + 15;
vector<pii> a[maxn];
int fav[maxn];

db dijkstra(int st){
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

    int sum = 0;
    for(int i = 0; i < k; i++){
        if(dis[fav[i]] == oo) return (db)oo;
        sum += dis[fav[i]];
    }
    return (db)sum / k;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>m;
    for(int i = 0; i < k; i++) cin>>fav[i];

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    db minn = oo, res = fav[0];
    for(int i = 1; i <= n; i++){
        db tmp = dijkstra(i);
        if(tmp < minn){
            minn = tmp;
            res = i;
        }
    }
    cout<<res;
    return 0;
}