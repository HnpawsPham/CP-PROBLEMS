#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 1e6 + 5;
vector<vector<int>> a(maxn);
bool check[maxn];

void dfs(int u){
    check[u] = 1;
    for(int v : a[u]){
        if(check[v]) continue; 
        check[v] = 1;
        dfs(v);
    }
    return;
}

int main(){
    freopen("ROUTE.INP", "r", stdin);
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

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(!check[i]){
            dfs(i);
            cnt++;
        }
    cout<<cnt - 1;
    return 0;
}