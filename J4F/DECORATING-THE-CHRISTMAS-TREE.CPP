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
const int maxn = 2e5 + 5;
int parent[maxn], sz[maxn], color[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
        color[i] = 0;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    int p = parent[x];

    parent[x] = find(parent[x]);
    color[x] = (color[x] + color[p]) % 2;
    return parent[x];
}

bool unite(int u, int v){
    int pu = find(u);
    int pv = find(v);

    if(pu == pv) return 0;    
    if(sz[pu] < sz[pv]) swap(pu, pv);

    sz[pu] += sz[pv];
    parent[pv] = pu;
    color[pv] = (color[v] + color[u] + 1) % 2;
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
        cin>>opt>>u>>v;
        if(opt == 1){
            if(find(u) != find(v))
                unite(u, v); 
        }
        else{
            if(find(u) == find(v)){
                if(color[u] ^ color[v] == 0) cout<<"Yes"<<el;
                else cout<<"No"<<el;
            }
            else cout<<"Merry Christmas!"<<el;
        }
    }

    return 0;
}