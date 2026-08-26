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
#define taskname "LGR"

int n, m;
const int maxn = 1e5 + 5;
vi a[maxn];
vector<pii> ed;
int sz[maxn], parent[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
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

    parent[v] = u;
    sz[u] += sz[v];
    sz[v] = 0;
    return 1;
}

namespace sub1{
    void sol(){
        ll res = n;

        for(int l = 1; l <= n; l++)
            for(int r = l + 1; r <= n; r++){
                makeset();
                for(const auto&[u, v] : ed){
                    if(u >= l && v <= r)
                        unite(u, v);
                }

                for(int i = l; i <= r; i++)
                    if(sz[find(i)] <= 2) res++;
            }
        cout<<res;
    }
}

namespace sub2{
    void sol(){
         ll res = n;

        for(int l = 1; l <= n; l++){
            makeset();
            ll tmp = 1;

            for(int r = l + 1; r <= n; r++){
                tmp++;

                for(const int& u : a[r]){
                    if(u >= l && u <= r){
                        int ru = find(u), rv = find(r);

                        if(ru != rv){
                            if(sz[ru] <= 2) tmp -= sz[ru];
                            if(sz[rv] <= 2) tmp -= sz[rv];
                        }

                        unite(u, r);
                        int root = find(u);
                        if(sz[root] <= 2) 
                            tmp += sz[root];
                    }
                }
                res += tmp;
            }
        }
        cout<<res;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        ed.push_back({min(u, v), max(u, v)});
    }

    if(n <= 300 && m <= 600) 
        sub1::sol();
    else sub2::sol();
    return 0;
}