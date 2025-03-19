#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 1e5 + 4;
vector<vector<int>> a(maxn);
bool check[maxn];

void dfs(int u){
    check[u] = 1;
    for(int v : a[u])
        if(!check[v])  dfs(v);
    return;
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    check[x] = 1;

    while(!q.empty()){
        int u = q.front(); 
        q.pop();

        for(int v : a[u]){
            if(!check[v]){
                q.push(v);
                check[v] = 1;
            }
        }
    }
    return;
}

int id = 0, cnt_scc = 0;
int low[maxn], idx[maxn];
stack<int> path;

void tarjan(int u){
    low[u] = idx[u] = id++;
    check[u] = 1;
    path.push(u);

    for(int v : a[u]){
        if(!idx[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(check[v])
            low[u] = min(low[u], idx[v]);
    }

    if(idx[u] == low[u]){
        while(1){
            int v = path.top();
            path.pop();

            check[v] = 0;
            if(v == u) break;
        }
        cnt_scc++;
    }
    return;
}

// void dijkstra(int src){
//     vector<int> dis(n + 1, INT_MAX);
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     pq.push({0, src});
//     dis[src] = 0;

//     while(!pq.empty()){
//         pii cur = pq.top();
//         pq.pop();

//         int u = cur.se;
//         int w = cur.fi;
//         if(w > dis[u]) continue;

//         for(pii x : a[u]){
//             int v = x.se;
//             int w1 = x.fi;

//             if(dis[u] + w1 < dis[v]){
//                 dis[v] = dis[u] + w1;
//                 pq.push({dis[v], v});
//             }
//         }
//     }
//     return;
// }



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    return 0;
}