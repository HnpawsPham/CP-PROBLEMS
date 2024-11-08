#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n, id = 0;
const int maxn = (int)1e5 + 5;
vector<vector<int>> a(maxn);
bool check[maxn];
int index[maxn];

void dfs(int u, int parent){
    index[u] = index[parent] + 1;
    check[u] = 1;

    for(int v : a[u]){
        if(!check[v]) dfs(v, u);
    }
    return;
}

int main(){
    freopen(".\\txt\\THU-TU-DINH.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n;i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    memset(index, 0, sizeof(index));
    dfs(1, 0);
    for(int i =1;i<=n;i++) cout<<char('A' + index[i] - 1)<<" ";

    return 0;
}