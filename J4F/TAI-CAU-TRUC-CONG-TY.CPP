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

int n, q;
const int maxn = 2e5 + 5;
int parent[maxn], sz[maxn], nextptr[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
        nextptr[i] = i;
    }
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int findnext(int x){
    if(x == nextptr[x]) return x;
    return nextptr[x] = findnext(nextptr[x]);
}

bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;
    if(sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
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

    cin>>n>>q;
    makeset();
    while(q--){
        int opt, u, v;
        cin>>opt>>u>>v;

        if(opt == 1)
            unite(u, v);
      
        else if(opt == 2){
            int cur = findnext(u);
            while(cur < v){
                unite(cur, cur + 1);
                nextptr[cur] = cur + 1;
                cur = findnext(cur);
            }
        }
        else cout<<(find(u) == find(v) ? "YES" : "NO")<<el;
    }
    return 0;
}