#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, q, res;
const int maxn = 1e5;
int sz[maxn], parent[maxn];

void make_set(){
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

void union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);

    sz[a] += b;
    parent[b] = a;
    sz[b] = 0;
    res--;
    return;
}

int main(){
    freopen("GRAPH.INP", "r", stdin);
    freopen("GRAPH.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    int u[m + 1], v[m + 1];
    for(int i = 1; i <= m; i++)
        cin>>u[i]>>v[i];

    while(q--){
        int l, r;
        cin>>l>>r;
        res = n;

        make_set();
        for(int i = l; i <= r; i++)
            union_set(u[i], v[i]);

        cout<<res<<el;
    }

    return 0;
}