#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n, m;
const int maxn = 10005;
vector<vector<int>> cyc(maxn); 
int parent[maxn], sz[maxn];

void makeSet(){
    for(int i = 1; i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b, int w){
    a = find(a);
    b = find(b);

    if(a == b) return;    
    if(sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    sz[b] = 0;

    int t = cyc[a].size() - 1;
    if (t > 0) cyc[a][t] = min(cyc[a][t], w);
    else cyc[a].push_back(w);
    
    return;
}

int main(){
    freopen(".\\txt\\NANGCAP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    makeSet();

    int sum = 0;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        
        unionSet(u, v, w);
        if(find(u) == find(v)){
            cout<<u<<" "<<v<<el;
            if(!cyc[u].empty()){
                cout<<u<<": ";
                for(int x : cyc[u]) cout<<x<<" ";
                cout<<el;
            }
            if(!cyc[u].empty()) sum += cyc[u][cyc[u].size() - 1];
        }
    }

    cout<<sum<<el;
    return 0;
}