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
#define taskname "TAITRONG"

int n, m, s, t;
const int maxn = 1e3 + 5;
const int oo = 1e7 + 17;
vector<pii> a[maxn];

int dijkstra(){
    vi maxx(n + 1, 0);
    priority_queue<pii> pq;
    maxx[s] = oo;
    pq.push({oo, s});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w < maxx[u]) continue;

        for(auto [w1, v] : a[u]){
            if(maxx[v] < min(maxx[u], w1)){
                maxx[v] = min(maxx[u], w1);
                pq.push({maxx[v], v});
            }
        }
    }
    return maxx[t];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s>>t;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    cout<<dijkstra();
    return 0;
}