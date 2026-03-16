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

int n, k;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
int parent[maxn], sz[maxn];

void makeset(){
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

bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;
    if(sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
    sz[v] = 0;
    return 1;
}

int ppow(int a, int b){
    if(b == 0) return 1;
    int half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    makeset();
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        if(w == 0) unite(u, v);
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!sz[i]) continue;
        res = (res + ppow(sz[i], k)) % MOD;
    }

    cout<<(ppow(n, k) - res + MOD) % MOD; 
    return 0;
}