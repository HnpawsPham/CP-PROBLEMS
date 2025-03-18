#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define LOG 20

int n, q;
const int maxn = 2 * 1e5 + 5;
vector<vector<int>> a(maxn);
int dis[maxn];

void dfs(int u, int x){
    dis[u] = 0;
    for(int v : a[u]){
        if(dis[v] == -1) {
            dis[v] = dis[u] + 1;
            dfs(v, x);
        } 
        if(v == x) return;
    }
    return;    
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    dis[x] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : a[u]){
            if(dis[v] == -1) continue;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }
    return;
}

int find_path(int u, int k){
    memset(dis, -1, sizeof(dis));
    bfs(u);

    for(int i = 1; i <= n; i++)
        if(dis[i] == k) return i;
    
    return -1;
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
    cin>>q;
    while(q--){
        int u, k;
        cin>>u>>k;
        cout<<find_path(u, k)<<el;
    }

    return 0;
}