#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m, bridge = 0, id = 0;
const int maxn = 1e5 + 5;
vector<vector<int>> a(maxn);
int low[maxn], idx[maxn] = {};

void tarjan(int u, int parent){
    low[u] = idx[u] = ++id;

    for(int v : a[u]){
        if(v == parent) continue;

        if(!idx[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if(low[u] == idx[v]) bridge++;
        }
        else low[u] = min(low[u], idx[v]);
    }
    return;
}

int main(){
    freopen("XAY-DUNG-DOANH-TRAI.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) if(!idx[i]) tarjan(i, 0);
    cout<<bridge;

    return 0;
}