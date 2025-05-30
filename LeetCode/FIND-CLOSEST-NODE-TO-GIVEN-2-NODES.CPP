#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, node1, node2;
vector<vi> a;
vi d, check;
vector<bool> vis;

void dfs(int u, int dis){
    d[u] = max(d[u], dis);
    check[u]++;
    vis[u] = 1;

    for(int v : a[u])
        if(!vis[v])
            dfs(v, dis + 1);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>node1>>node2;
    vi t(n);
    for(int i = 0; i < n; i++) cin>>t[i];

    a.resize(n);
    d.assign(n, 0);
    check.assign(n, 0);
    vis.assign(n, 0);

    for(int i = 0; i < n; i++)
        if(t[i] != -1) 
            a[i].push_back(t[i]);

    // d[node1] = d[node2] = n + 1;

    dfs(node1, 0);
    vis.assign(n, 0);
    dfs(node2, 0);

    int minn = n + 1, res = -1;
    for(int i = 0; i < n; i++)
        if(check[i] == 2 && d[i] < minn){
            minn = d[i];
            res = i;
        }
    cout<<res;
    return 0;
}