#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<db, int>
#define fi first
#define se second

int n, m, speed;
const int maxn = 2e5 + 5;
const db oo = 1e12;
vector<pii> a[maxn];
int in[maxn] = {0};
int s, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>speed;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    cin>>s>>t;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<db> dis(n + 1, oo);
    dis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        
        if(w > dis[u]) continue;
        if(u == t) break;

        for(auto [w1, v] : a[u]){
            db len = w1 / (db)speed;
            if(v != s && v != t && a[v].size() >= 3) 
                len += (int)a[v].size() - 2;

            if(dis[v] > dis[u] + len){
                dis[v] = dis[u] + len;
                pq.push({dis[v], v});
            }
        }
    }
    cout<<fixed<<setprecision(6)<<dis[t];
    return 0;
}

// 3 3 7
// 1 2 8
// 2 3 9
// 1 3 20
// 1 3

// 5 6 1
// 1 2 5
// 2 3 5
// 1 4 10
// 4 3 2
// 3 5 3
// 4 5 8
// 1 5
