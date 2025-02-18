#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = 2 * (int)1e5 + 5;
vector<vector<int>> a(maxn);
int sz[maxn];

int dfs(int u, int parent){
    int &res = sz[u];
    res = 1;

    for(int v : a[u]){
        if(v == parent) continue;
        res += dfs(v, u);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 2;i<=n;i++){
        int u;
        cin>>u;
        a[u].push_back(i);
    }
    dfs(1, 0);

    for(int i = 1;i<=n;i++) cout<<sz[i] - 1<<" ";
    return 0;
}