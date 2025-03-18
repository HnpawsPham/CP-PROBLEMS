#include <iostream>
#pragma GCC optimize("O2")
using namespace std;
#define el "\n"

int n, m;
const int maxn = 1e5 + 5;
int sz[maxn], parent[maxn];

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    
    parent[b] = a;
    sz[a] += sz[b];

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    make_set();

    while(m--){
        string opt;
        int u, v;
        cin>>opt>>u>>v;
        
        if(opt == "union") union_set(u, v);
        else cout<<(find(u) == find(v) ? "YES" : "NO")<<el; 
    }
    return 0;
}