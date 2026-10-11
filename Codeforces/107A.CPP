#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define fi first
#define se second
//#define taskname ""

int n, m;
const int maxn = 1005;
int in[maxn], out[maxn];
vector<pii> a[maxn];
vector<piii> res;
bitset<maxn> check;

void dfs(int root, int u, int w){
    bool en = 1;
    for(auto [w1, v] : a[u]){
        if(check[v]) continue;
        dfs(root, v, min(w, w1));
        en = 0;
    }

    if(en) res.push_back({w, {root, u}});
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
    if(m == 0) return cout<<0, 0;
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    check.reset();

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        in[v]++;
        out[u]++;
        a[u].push_back({w, v});
    }

    for(int i = 1; i <= n; i++)
        if(in[i] == 0 && out[i]) dfs(i, i, 1e6 + 5);
    
    cout<<res.size()<<el;
    for(const piii& x : res)
        cout<<x.se.fi<<" "<<x.se.se<<" "<<x.fi<<el;
    return 0;
}