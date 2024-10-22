#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n, m;
const int maxn = 10005;
vector<vector<pii>> a(maxn);
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

bool unionSet(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return false;    
    if(sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    sz[b] = 0;

    return true;
}

int main(){
    freopen(".\\txt\\NANGCAP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        
        if(unionSet(u, v)){}
    }

    return 0;
}