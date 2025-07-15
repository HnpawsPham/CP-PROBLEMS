#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, q;
const int maxn = 1e5 + 5;
int parent[maxn], sz[maxn], sum[maxn], del[maxn];

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
        sum[i] = del[i] = 0;
    }
    return;
}

int find(int x){
    if(x != parent[x]){
        int root = find(parent[x]);
        del[x] += del[parent[x]];
        parent[x] = root;
        return root;
    }
    return x;
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    del[b] = sum[b] - sum[a];

    return;
}

void add(int a, int val){
    int root = find(a);
    sum[root] += val;
    return;
}

int get(int a){
    int root = find(a);
    return sum[root] + del[a];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    make_set();

    string opt;
    int u, v;

    while(q--){
        cin>>opt>>u;
        if(opt == "get"){
            cout<<get(u)<<el;
            continue;
        }
        cin>>v;
        if(opt == "join")
            union_set(u, v);
        else if(opt == "add")
            add(u, v);
    }

    return 0;
}
// 4 10
// join 1 2
// add 1 100
// join 2 3
// add 1 50
// join 3 4
// add 1 25
// get 1
// get 2
// get 3
// get 4
