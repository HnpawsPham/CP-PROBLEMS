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

struct line{
    int u, v;
    line(){};
    line(int u1, int v1) : u(u1), v(v1) {};
};

int n;
const int maxn = 1e5 + 5;

class DSU{
private: 
    int sz[maxn], parent[maxn];

public:
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

        sz[u] += sz[v];
        parent[v] = u;
        return 1;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int m;
    cin>>m;
    vector<vi> ed(m, vi(3));
    for(int i= 0; i < m;i++)
        cin>>ed[i][0]>>ed[i][1]>>ed[i][2];    

    int cnta = 0, cntb = 0, cnt = 0;
    DSU a, b;
    a.makeset();
    b.makeset();

    for(const vi& v : ed){
        if(v[0] == 3){
            bool ua = a.unite(v[1], v[2]);
            bool ub = b.unite(v[1], v[2]);
            if(ua || ub){
                cnta += ua;
                cntb += ub;
                cnt++;
            }
        }
    }

    for(const vi& v: ed){
        if(v[0] == 1 && a.unite(v[1], v[2])) 
            cnta++;
            
        else if(v[0] == 2 && b.unite(v[1], v[2])) 
            cntb++;
    }

    if(cnta != n - 1 || cntb != n - 1)
        return cout<<-1, 0;

    cout<<m - (cnta + cntb - cnt);
    return 0;
}

// 4 6
// 3 1 2
// 3 2 3
// 1 1 3
// 1 2 4
// 1 1 2
// 2 3 4

// 4 4
// 3 1 2
// 3 2 3
// 1 1 4
// 2 1 4

// 4 3
// 3 2 3
// 1 1 2
// 2 3 4