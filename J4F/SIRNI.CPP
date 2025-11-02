#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 1e7 + 2;
int parent[maxn], sz[maxn], p[maxn] = {0};
bool check[maxn] = {0};
vector<pii> ed[maxn];

void make_set(){
    for(int i = 0; i < maxn; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);
    
    sz[a] += sz[b];
    parent[b] = a;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    int maxx = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        maxx = max(maxx, a[i]);
        check[a[i]] = 1;
    }
 
    make_set();
    for(int i = maxx; i > 0; i--){
        if(check[i]) p[i] = i;
        else p[i] = p[i + 1];
    }

    for(int u = 1; u <= maxx; u++){
        if(!check[u]) continue;

        int v = p[u + 1];
        if(v && v <= 2 * u)
            ed[min(u % v, v % u)].push_back({u, v});

        v = 2 * u;
        for(; v <= maxx; v += u){
            if(p[v] && p[v] < u + v)
                ed[min(u % p[v], p[v] % u)].push_back({u, p[v]});
        }
    }
        
    ll res = 0;
    for(int w = 0; w < maxx; w++)
        for(const auto& [u, v] : ed[w])
            if(unite(u, v)) res += w;
    cout<<res;
    return 0;
}