#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, q;
const int maxn = 1e5 + 5;
int sz[maxn], parent[maxn];

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 0;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int get(int x){
    return sz[x];
}

void add(int u, int x){
    u = find(u);
    sz[u] += x;
    for(int i = 1; i <=n ;i++)
        if(i != u && find(i) == u) sz[i] += x;
    return;
}

void union_set(int u, int v){
    u = find(u);
    v = find(v);

    if(u != v) 
        parent[v] = u;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    make_set();

    while(q--){
        string opt;
        int x, y;
        cin>>opt>>x;

        if(opt == "get"){
            cout<<get(x)<<el;
            continue;
        }
        cin>>y;
        if(opt == "join")
            union_set(x, y);
        else add(x, y);
    }

    return 0;
}