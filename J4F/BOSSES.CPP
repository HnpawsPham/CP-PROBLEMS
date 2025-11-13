#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 3e5 + 5;
int parent[maxn], h[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        h[i] = 0;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    int p = parent[x];
    parent[x] = find(parent[x]);
    h[x] += h[p];
    return parent[x];
}

bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;
    
    parent[u] = v;
    h[u] = 1;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    makeset();

    while(m--){
        int opt, u, v;
        cin>>opt>>u;
        if(opt == 1) {
            cin>>v;
            unite(u, v);
        }
        else{
            find(u);
            cout<<h[u]<<el;
        }
    }
    return 0;
}