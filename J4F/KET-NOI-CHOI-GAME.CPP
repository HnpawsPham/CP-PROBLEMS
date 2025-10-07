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
const int maxn = 1e5 + 5;
int parent[maxn], cnt[maxn], res[maxn];
unordered_map<int, int> mp[maxn];

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b, int x){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(mp[a].size() < mp[b].size()) swap(a, b);

    parent[b] = a;
    for(auto [color, w] : mp[b]){
        mp[a][color] += w;
        if(mp[a][color] == cnt[color] && res[color] == -1)
            res[color] = x;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m>>q;

    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        cnt[x]++;
        parent[i] = i;
        mp[i][x]++;
    }

    for(int i = 1; i <= m; i++){
        res[i] = -1;
        if(cnt[i] == 1) res[i] = 0;
    }
    
    for(int i = 1; i <= q; i++){
        int u, v;
        cin>>u>>v;
        unite(u, v, i);
    }

    for(int i = 1; i <= m; i++) 
        cout<<res[i]<<el;
    return 0;
}