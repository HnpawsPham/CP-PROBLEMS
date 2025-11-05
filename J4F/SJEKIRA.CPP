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

int n;
const int maxn = 1e5 + 5;
int k[maxn], parent[maxn], maxx[maxn];
ll res = 0;

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        maxx[i] = k[i];
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
    if(maxx[u] < maxx[v]) swap(u, v);

    parent[v] = u;
    res += maxx[u] + maxx[v];
    maxx[u] = max(maxx[u], maxx[v]);
    return 1; 
}

bool comp(const pii& a, const pii& b){
    return max(k[a.fi], k[a.se]) < max(k[b.fi], k[b.se]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>k[i];
    makeset();

    vector<pii> ed;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        ed.push_back({u, v});
    }
    sort(ed.begin(), ed.end(), comp);

    for(auto [u, v] : ed) unite(u, v);
    cout<<res;
    return 0;
}