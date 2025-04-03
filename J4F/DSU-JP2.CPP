#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#pragma GCC optimize("O2,Ofast,unroll-loops")

struct line{
    int u, v, w;
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {};
};

int n, m;
const int maxn = 2e5 + 4;
int parent[maxn], sz[maxn];
vector<line> a;

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
    return 1;
}

bool comp(line a, line b){
    return a.w < b.w;
}

ll kruskal(){
    ll res = 0, msize = 0;
    sort(a.begin(), a.end(), comp);

    for(int i = 0; i < m; i++){
        if(msize == n - 1) break;

        if(union_set(a[i].u, a[i].v)){
            msize++;
            res += a[i].w;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a.emplace_back(u, v, w);
    }
    make_set();
    cout<<kruskal();
    return 0;
}