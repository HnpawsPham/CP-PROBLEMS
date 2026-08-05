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
bool check[maxn];
vi a[maxn];

void dfs(int u){
    check[u] = 1;
    for(int v : a[u]){
        if(!check[v])
            dfs(v);
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

    int n, k, m;
    cin>>n>>k>>m;
    vector<vi> ed(m, vi(2));
    for(int i = 0; i < m; i++)
        cin>>ed[i][0]>>ed[i][1];

    memset(check, 0, sizeof check);

    for(const vi& v : ed)
        a[v[0]].push_back(v[1]);

    dfs(k);
    for(const vi& v : ed)
        if(check[v[0]] != check[v[1]]){
            vi res(n);
            iota(res.begin(), res.end(), 0);
            for(int x : res) cout<<x<<" ";
            return 0;
        }
    
    vi res;
    for(int i = 0; i < n; i++)
        if(!check[i]) res.push_back(i);
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 4 1 3
// 1 2
// 0 1
// 3 2

// 5 0 4
// 1 2
// 0 2
// 0 1
// 3 4