#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, q, maxdis, S, T;
const int maxn = 2 * 1e5 + 5;
vector<vector<int>> a(maxn);
// int dis[maxn];

// SUB 1
// void bfs(int x, int k){
//     queue<int> q;
//     q.push(x);
//     dis[x] = 0;

//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
        
//         if(dis[u] == k) continue;

//         for(int v : a[u]){  
//             if(dis[v] != -1) continue;
//             dis[v] = dis[u] + 1;
//             q.push(v);
//         }
//     }
//     return;
// }

// int find(int u, int k){
//     memset(dis, -1, sizeof(dis));
//     bfs(u, k);

//     for(int i = 1; i <= n; i++)
//         if(dis[i] == k) return i;
    
//     return -1;
// }

// SUB 2
void dfs(int u, int parent, int dis, int& res){
    if(dis > maxdis){
        maxdis = dis;
        res = u;
    }
    
    for(int v : a[u])
        if(v != parent) dfs(v, u, dis + 1, res);
}

vector<pii> que[maxn];
vector<int> res, path;

void find(int u, int parent){
    for(pii x : que[u]){
        int sz = path.size();

        if(x.se <= (int)path.size()) 
            res[x.fi] = path[sz - x.se]; 
    }
    path.push_back(u);
    for(int v : a[u])
        if(v != parent) find(v, u);
    path.pop_back();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    maxdis = -1;
    dfs(1, -1, 0, S);

    maxdis = -1;
    dfs(S, -1, 0, T);

    cin>>q;
    res.assign(q, -1);

    for(int i = 0; i < q; i++){
        int u, k;
        cin>>u>>k;
        que[u].push_back({i, k});
    }   

    find(S, -1);
    find(T, -1);

    for(int x : res) cout<<x<<el;

    return 0;
}