#include <bits/stdc++.h>
using namespace std;
#define el "\n"

struct line{
    int u, v, w;
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};
};

int n, m;
const int maxn = 10005;
vector<line> a;
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

bool union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    sz[b] = 0;

    return 1;
}

bool compare(line a, line b){
    return a.w < b.w;
}

void kruskal(){
    int msize = 0;
    vector<line> mst;

    sort(a.begin(), a.end(), compare);

    for(int i = 0; i < m; i++){
        if(mst.size() == n - 1) break;

        if(union_set(a[i].u, a[i].v)){
            mst.push_back(a[i]);
            msize += a[i].w;
        }
    }

    cout<<(mst.size() == n - 1 ? msize : 0);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        
        a.push_back({u, v, w});
    }

    make_set();
    kruskal();

    return 0;
}