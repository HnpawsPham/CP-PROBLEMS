#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e5 + 5;
vector<vector<int>> a(maxn);
bool check[maxn], isCen[maxn];
int subsz[maxn];

void dfs(int u, int cnt){
    check[u] = 1;
    subsz[u] = 1;

    for(int v : a[u]){
        if(check[v] || isCen[v]) continue;
        dfs(v, cnt + 1);
        subsz[u] += subsz[v];
    }
    return;
}

int getCen(int u){
    memset(check, 0, sizeof(check));
    memset(subsz, 0, sizeof(subsz));

    int cen = getCen(u);
    isCen[cen] = 1;

    return cen;
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

    return 0;
}