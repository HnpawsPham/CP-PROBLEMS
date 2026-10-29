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

int n, k;
const int LOG = 16;
const int maxn = 5e4 + 5;
vi a[maxn];
int h[maxn], p[maxn][LOG + 1], tin[maxn], tout[maxn], t = 0;
int bit[maxn];
string s;

void add(int i, int val){
    while(i <= n){
        bit[i] ^= val;
        i += (i & -i);
    }
}

int query(int i){
    int res = 0;
    while(i > 0){
        res ^= bit[i];
        i -= (i & -i);
    }
    return res;
}

void update(int l, int r, int val){
    add(l, val);
    add(r + 1, val); // a ^ a = 0
}

void dfs(int u){
    tin[u] = ++t;
    for(int v : a[u]){
        if(v == p[u][0]) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
    tout[u] = t;
}

void prep(){
    h[0] = 0;
    p[0][0] = 0;
    dfs(0);

    for(int j = 1; j <= LOG; j++)
        for(int i = 0; i < n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);

    for(int i = LOG; i >= 0; i--)
        if(h[p[u][i]] >= h[v])
            u = p[u][i];
    if(u == v) return u;

    for(int i = LOG; i >= 0; i--)
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}

bool check(int mask){
    return __builtin_popcount(mask) <= 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s>>k;
    vector<vi> ed(n - 1, vi(2));
    for(int i = 0; i < n - 1; i++)
        cin>>ed[i][0]>>ed[i][1];

    vector<string> q(k);
    cin.ignore();
    for(int i = 0; i < k; i++)
        getline(cin, q[i]);

    for(const vi& v : ed){
        a[v[0]].push_back(v[1]);
        a[v[1]].push_back(v[0]);
    }

    prep();
    memset(bit, 0, sizeof bit);
    for(int i = 0; i < n; i++)
        update(tin[i], tout[i], (1 << (s[i] - 'a')));

    vector<bool> res;
    for(const string& tmp: q){
        stringstream ss(tmp);
        string opt;
        ss >> opt;
        
        if(opt == "update"){
            int u;
            char c;
            ss>>u>>c;

            update(tin[u], tout[u], (1 << (s[u] - 'a')) ^ (1 << (c - 'a')));
            s[u] = c;
        }
        else{
            int u, v;
            ss>>u>>v;
            res.push_back(check(query(tin[u]) ^ query(tin[v]) ^ (1 << (s[lca(u, v)] - 'a'))));
        }
    }

    for(const bool& x : res)
        cout<<x<<" ";
    return 0;
}

// 4 abca 5
// 0 1
// 0 2
// 0 3
// query 1 2
// update 0 b
// query 2 3
// update 3 a
// query 1 3