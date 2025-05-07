#include <bits/stdc++.h>
using namespace std;
#define el "\n"
using ll = long long;
#define vi vector<int>
#define vll vector<ll>
#define piii pair<ll, pair<int, int>>
#define fi first
#define se second

int n, m;
vector<vi> a;
int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};
const ll oo = 1e18;

int dijkstra(int si, int sj){
    priority_queue<piii, vector<piii>, greater<piii>> pq;
    vector<vll> dis(n, vll(m, oo));
    
    dis[si][sj] = 0;
    pq.push({0, {si, sj}});

    while(!pq.empty()){
        ll w = pq.top().fi;
        int i = pq.top().se.fi;
        int j = pq.top().se.se;
        pq.pop();

        if(dis[i][j] < w) continue;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || i1 >= n || j1 < 0 || j1 >= m) continue;

            ll newdis = max(w, (ll)a[i1][j1]) + 1;
            if (dis[i1][j1] > newdis) {
                dis[i1][j1] = newdis; 
                pq.push({newdis, {i1, j1}}); 
            }
        }
    }
    return dis[n-1][m-1];;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        a.push_back({u, v});
    }

    dijkstra(0, 0);
    return 0;
}