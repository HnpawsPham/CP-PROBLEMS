#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 10005;
vector<vector<int>> a(maxn);
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

    sz[a] += sz[b];
    parent[b] = a;
    sz[b] = 0;

    return;
}

int main(){
    freopen("KD.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    make_set();
    while(m--){
        int u, v;
        cin>>u>>v;
        union_set(u, v);
    }
    sort(sz, sz + n, greater<int>());
    cout<<sz[0] + sz[1];

    return 0;
}