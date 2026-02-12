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
//#define taskname ""

int n, q;
const int maxn = 2e5 + 5;
int parent[maxn], sz[maxn], diff[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
        diff[i] = 0;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    int p = parent[x];
    parent[x] = find(parent[x]);
    diff[x] ^= diff[p];
    return parent[x];
}

bool unite(int u, int v, int d){
    int rootu = find(u);
    int rootv = find(v);

    if(rootu == rootv) return 0;
    if(sz[rootu] < sz[rootv]){
        swap(u, v);
        swap(rootu, rootv);
    }
    
    sz[rootu] += sz[rootv];
    parent[rootv] = rootu;
    diff[rootv] = diff[u] ^ diff[v] ^ d;
    return 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    int a[n + 1];
    memset(a, -1, sizeof a);
    makeset();
    
    while(q--){
        int opt, x, y;
        cin>>opt>>x>>y;

        if(opt == 0) unite(x, y, 0);
        else if(opt == 1) unite(x, y, 1);
        else{
            if(find(x) != find(y)) cout<<-1<<el;
            else cout<<(diff[x] ^ diff[y])<<el;
        }
    }
    return 0;
}