#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

struct line{
    int u, v;
    ll w;
    line(int u1, int v1, ll w1) : u(u1), v(v1), w(w1) {};
};

bool comp(line a, line b){
    return a.w < b.w;
}

int n, m;
const int maxn = 1005;
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin>>u>>v>>w;
        a.emplace_back(u, v, w);
    }

    if(m < n - 1) return cout<<"NOT FOUND";

    make_set();
    sort(a.begin(), a.end(), comp);

    return 0;
}