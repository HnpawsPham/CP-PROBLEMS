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
#define taskname "XGEN"

int n, q, cnt = 0, t = 0;
const int maxn = 2e5 + 5;
const int LOG = 18;
string a[maxn];
int child[maxn][26], id[maxn];
int h[maxn], p[maxn][LOG + 1], in[maxn];

void add(string& s, int pos){
    int u = 0;
    int n = s.length();

    for(int i = 0; i < n; i++){
        int k = s[i] - 'a';
        if(!child[u][k])
            child[u][k] = ++cnt;
        u = child[u][k];
    }
    id[pos] = u;
}

void dfs(int u, int parent){
    in[u] = ++t;

    for(int i = 0; i < 26; i++){
        int v = child[u][i];
        if(!v) continue;

        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

void prep(){
    h[0] = 0;
    dfs(0, 0);

    for(int j = 1; j <= LOG; j++)
        for(int i = 1; i < maxn; i++)
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
            v= p[v][i];
        }

    return p[u][0];
}

bool comp(int a, int b){
    return in[id[a]] < in[id[b]];
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
    memset(child, 0, sizeof child);

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        add(a[i], i);
    }
    prep();

    while(q--){
        int k, m;
        cin>>m>>k;

        int sub[m];
        for(int i =0; i < m; i++)  
            cin>>sub[i];
        
        // sub3
        if(k == m){
            sort(sub, sub + m, comp);
            cout<<h[lca(id[sub[0]], id[sub[m - 1]])]<<el;
        }
        else{
            
        }
    }
    return 0;
}