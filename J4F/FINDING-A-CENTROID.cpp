#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = 2 * (int)1e5 + 5;
vector<vector<int>> a(maxn);
int sz[maxn];

void getsz(int u, int parent){
    sz[u] = 1;
    
    for(int v : a[u]){
        if(v == parent) continue;
        getsz(v, u);
        sz[u] += sz[v];   
    }
    return;
}

int getCen(int u, int parent){
    for(int v : a[u]){
        if(v == parent) continue;
        if(sz[v] > n / 2) return getCen(v, u);
    }
    return u;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <n;i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    getsz(1, 0);
    cout<<getCen(1, 0)<<el;

    return 0;
}