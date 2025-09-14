#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, q;
const int maxn = 5e4 + 5;
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

void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b])swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    while(m--){
        int u, v;
        cin>>u>>v;
    }

    makeset();

    string opt[q];
    pii que[q];
    for(int i = 0; i < q; i++){
        int u, v;
        cin>>opt[i]>>u>>v;
        que[i] = {u, v};
    }

    vector<string> res;
    for(int i = q - 1; i >= 0; i--){
        auto [u, v] = que[i];

        if(opt[i] == "ask")
            res.push_back((find(u) == find(v) ? "YES" : "NO"));
        else unite(u, v);
    }
    reverse(res.begin(), res.end());
    for(const string& x : res) cout<<x<<el;
    return 0;
}