#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m, id = 0, cnt = 0;
const int maxn = (int)1e4 + 5;
vector<vector<int>> a(maxn);
bool check[maxn];
int idx[maxn], low[maxn];
stack<int> path;

void dfs(int u){
    path.push(u);
    check[u] = 1;
    idx[u] = low[u] = id++;

    for(int v : a[u]){
        if(!idx[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(check[v]){
            low[u] = min(idx[v], low[u]);
        }
    }

    if(low[u] == idx[u]){
        while(1){
            int v = path.top();
            path.pop();

            check[v] = 0;

            if(u == v) break;
        }
        cnt++;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }

    for(int i = 1; i <= n; i++)
        if(!idx[i]) dfs(i);
       
    cout<<cnt;

    return 0;
}