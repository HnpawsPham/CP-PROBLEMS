#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct line{
    int u, v, w;
    line(int u1, int v1, int w1) : u(u1), v(v1), w(w1) {}; 
};

int n, m;
const int maxn = 2e5 + 4;
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
    return 1;
}

bool comp(line a, line b){
    return a.w < b.w;
}

int kruskal(){
    int res = 0, msize = 0;
    sort(a.begin(), a.end(), comp);

    for(int i = 0; i < m; i++){
        if(msize == n - 1) break;

        if(union_set(a[i].u, a[i].v)){
            res = max(res, a[i].w);
            msize++;
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
        line l(u, v, w);
        a.push_back(l);
    }
    make_set();
    cout<<kruskal();
    
    return 0;
}