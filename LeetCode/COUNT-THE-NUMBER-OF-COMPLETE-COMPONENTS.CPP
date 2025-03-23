#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;
const int maxn = 1e5;
vi a[maxn];
int parent[maxn], sz[maxn];

void make_set(){
    for(int i = 0; i < n; i++){
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
    sz[b] = 0;
    return;
}

int main(){
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
    make_set();

    for(vi v : a)
        union_set(v[0], v[1]);

    unordered_map<int, int> edge_cnt;

    for(vi v : a){
        int src = find(v[0]);
        edge_cnt[src]++;
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        if(find(i) == i)
            if(edge_cnt[i] == sz[i] * (sz[i]  - 1) / 2) res++;
    cout<<res;

    return 0;
}