#include <iostream>
using namespace std;
#define el "\n"
#pragma GCC optimize("O2")

int n, m;
const int maxn = 3e5;
int parent[maxn], sz[maxn], max_node[maxn], min_node[maxn];

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = max_node[i] = min_node[i] = i;
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
    max_node[a] = max(max_node[a], max_node[b]);
    min_node[a] = min(min_node[a], min_node[b]);
    return;
}

void get(int x){
    x = find(x);
    cout<<min_node[x]<<" "<<max_node[x]<<" "<<sz[x]<<el;
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
        cin>>opt>>u;

        if(opt == "get"){
            get(u);
            continue;
        }

        cin>>v;
        union_set(u, v);
    }

    return 0;
}