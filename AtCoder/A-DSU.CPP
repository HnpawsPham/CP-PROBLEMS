#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, q;
const int maxn = 2e5 + 5;
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

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    
    sz[a] += sz[b];
    parent[b] = a;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    make_set();

    int opt, u, v;
    while(q--){
        cin>>opt>>u>>v;
        if(opt == 0) unite(u, v);
        else cout<<(find(u) == find(v))<<el;
    }
    return 0;
}