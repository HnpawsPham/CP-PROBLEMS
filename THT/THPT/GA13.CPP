#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, m, s, p, id = 0, scc = 0;
const int maxn = 500000;
int shop[maxn], money[maxn], sccId[maxn];
vector<vector<int>> a(maxn), gr(maxn);
int low[maxn], idx[maxn] = {0};
bool check[maxn] = {0};
stack<int> path;

void dfs(int u){
    low[u] = idx[u] = id++;
    path.push(u);
    check[u] = 1;

    for(int v : a[u]){
        if(!idx[v]){
            dfs(v);
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
            sccId[v] = scc;

            if(u == v) break;
        }
        scc++;
    }
    return;
}

void build(){
    for(int i = 1; i <= n; i++)
        gr[sccId[i]].push_back(i);
    return;
}

int main(){
    // freopen("GA13.inp", "r", stdin);
    // freopen("GA13.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) cin>>money[i];
    cin>>s>>p;
    for(int i = 1; i <= p; i++)
        cin>>shop[i];

    for(int i = 1; i <= n; i++)
        if(!idx[i]) dfs(i);

    build();

    for(vector<int> v : gr){
        for(int x : v) cout<<x<<" ";
        if(!v.empty())
        cout<<el;
    }
    return 0;
}