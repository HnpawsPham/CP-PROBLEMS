#include <iostream>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 1e4 + 4;
const int INF = 3e6;
int parent[maxn], sz[maxn];

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

    for(int i = 2; i <= n; i++){
        int u, w;
        cin>>u>>w;
        if(w == 1) union_set(i, u);
    }

    while(m--){
        int u, v;
        cin>>u>>v;
        cout<<(find(u) != find(v) ? "YES" : "NO")<<el;
    }
    return 0;
}