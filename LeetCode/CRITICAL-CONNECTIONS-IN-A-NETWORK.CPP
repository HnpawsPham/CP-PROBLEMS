#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m, id = 0;
const int maxn = 1e5 + 4;
vector<vi> a, res;
int idx[maxn] = {0}, low[maxn];

void tarjan(int u, int parent){
    idx[u] = low[u] = id++;

    for(int v : a[u]){
        if(!idx[v]){
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > idx[u])
                res.push_back({u, v});
        }
        else if(v != parent)
            low[u] = min(low[u], idx[v]);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    a.resize(n);
    
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i = 0; i < n ;i++)
        if(!idx[i]) tarjan(i, 0);
    
    for(vi v : res)
        cout<<v[0]<<" "<<v[1]<<el;
    return 0;
}