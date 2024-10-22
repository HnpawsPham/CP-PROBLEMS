#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 1005;
vector<vector<int>> a;
int parent[maxn], sz[maxn];

void makeSet(){
    sz[0] = 0;
    for(int i = 1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b){
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
    freopen(".\\txt\\CONNECT.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    makeSet();
    while(m--){
        int u, v;
        cin>>u>>v;
        unionSet(u, v);
    }
    sort(sz, sz + n, greater<int>());
    cout<<sz[0] + sz[1]<<el;

    return 0;
}