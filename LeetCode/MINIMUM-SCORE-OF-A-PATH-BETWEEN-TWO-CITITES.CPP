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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vector<pii>> a(n + 1);
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dis(n + 1, 10005);
    pq.push({dis[1], 1});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        for(auto [w1, v] : a[u])
            if(dis[v] > min(w, w1)){
                dis[v] = min(w, w1);
                pq.push({dis[v], v});
            }
    }
    cout<<dis[n];
    return 0;
}

// 4 4
// 1 2 9
// 2 3 6
// 2 4 5
// 1 4 7