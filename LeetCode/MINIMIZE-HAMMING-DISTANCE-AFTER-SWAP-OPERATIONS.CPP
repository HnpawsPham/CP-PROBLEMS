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

int n;
const int maxn = 1e5 + 5;
int parent[maxn], sz[maxn];

void makeset(){
    for(int i = 0; i < n; i++){
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

    sz[u] += sz[v];
    parent[v] = u;
    return 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    int m;
    cin>>m;
    int q[m][2];
    for(int i = 0; i < m; i++)
        cin>>q[i][0]>>q[i][1];

    makeset();
    for(const auto& x : q)
        unite(x[0], x[1]);

    unordered_map<int, vi> mp;
    for(int i = 0; i < n; i++)
        mp[find(i)].push_back(i);

    int res = 0;
    for(const auto& [_, v] : mp){
        unordered_map<int, int> cnt;
        for(const int& x : v) cnt[a[x]]++;
        for(const int& x : v)
            if(cnt[b[x]] > 0) cnt[b[x]]--;
            else res++;
    }
    cout<<res;
    return 0;
}

// 4
// 1 2 3 4
// 2 1 4 5
// 2
// 0 1
// 2 3