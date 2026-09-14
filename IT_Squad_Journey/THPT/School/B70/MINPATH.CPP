#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define plii pair<ll, pii>
#define fi first
#define se second
#define taskname "MINPATH"

int n, m, cost, lim, k;
const int maxn = 1e4 + 5;
const ll oo = 1e12 + 5; 
vector<pii> a[maxn];

namespace sub2{
    void sol(){
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
        cout<<dis[n];
    }
}

namespace sub3{
    const int maxsz = 305;
    int cntlen[maxsz][maxsz];

    void bfs(int u){        
        queue<int> q;
        vi dis(n + 1, maxn * 5);
        q.push(u);
        dis[u] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto [w, v] : a[u]){
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        for(int i = 1; i <= n; i++)
            cntlen[u][i] = dis[i];
    }

    void sol(){
        for(int i = 1; i <= n; i++)
            bfs(i);

        priority_queue<plii, vector<plii>, greater<plii>> pq;
        vector<vll> dis(n + 1, vll(k + 1, oo));
        dis[1][k] = 0;  
        pq.push({0, {1, k}});

        while(!pq.empty()){
            auto [w, state] = pq.top();
            auto [u, left] = state;
            pq.pop();

            if(w > dis[u][left]) continue;

            if(left > 0){
                for(int v = 1; v <= n; v++){
                    if(v == u || cntlen[u][v] > lim) continue;
                    if(dis[v][left - 1] > dis[u][left] + cost){
                        dis[v][left - 1] = dis[u][left] + cost;
                        pq.push({dis[v][left - 1], {v, left - 1}});
                    }
                }
            }

            for(auto [w1, v] : a[u]){
                if(dis[v][left] > dis[u][left] + w1){
                    dis[v][left] = dis[u][left] + w1;
                    pq.push({dis[v][left], {v, left}});
                }
            }
        }
        cout<<*min_element(dis[n].begin(), dis[n].end());
    }
}


int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>cost>>lim>>k;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    if(k == 0) sub2::sol();
    // else if(n <= 300) sub3::sol();
    else sub3::sol();
    return 0;
}