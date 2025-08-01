#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, q;
const int maxn = 1e5 + 5;
int parent[maxn], sz[maxn], sum[maxn], del[maxn];

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
        sum[i] = 0;
        del[i] = 0;
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
    del[b] = sum[b] - sum[a];
    sz[a] += sz[b];
    return;
}

int get(int a){
    int root = find(a);
    return sum[root] + del[a];
}

void add(int a, int val){
    a = find(a);
    sum[a] += val;
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