#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second

int n, q;
const int maxn = 1e5 + 5;
int parent[maxn];
vector<unordered_map<int, int>> color;

void make_set(){
    color.resize(n + 1);

    for(int i = 1; i <= n; i++)
        parent[i] = i;
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
    if(color[a].size() < color[b].size()) 
        swap(a, b);

    parent[b] = a;
    for(auto& x : color[b])
        color[a][x.fi] += x.se;

    color[b].clear();
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    make_set();

    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        color[i][x]++;
    }

    int opt, u, v;
    while(q--){
        cin>>opt>>u>>v;
        if(opt == 1) union_set(u, v);
        else cout<<color[find(u)][v]<<el;
    }

    return 0;
}